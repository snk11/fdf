/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 15:18:28 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 12:19:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				ft_concat(char **line, t_env **env)
{
	char	*str;
	int		len;
	int		i;

	len = (*line ? ft_strlen(*line) : 0);
	i = (*env)->index;
	while (i < (*env)->ret && (*env)->buf[i] != '\n')
		i++;
	if (!(str = (char*)malloc(sizeof(str) * (len + i + 1))))
		return (0);
	ft_bzero(str, len + i + 1);
	if (*line)
	{
		ft_strcpy(str, *line);
		free(*line);
	}
	ft_strncat(str, &((*env)->buf[(*env)->index]), i - (*env)->index);
	*line = str;
	if (i < (*env)->ret)
	{
		(*env)->index = i + 1;
		return (1);
	}
	(*env)->index = 0;
	return (0);
}

static int				ft_freefdlist2(int fd, t_list **prev, t_list **curr)
{
	while (*prev && *curr)
	{
		if (fd && ((t_env*)(*curr)->content)->fd == fd)
		{
			(*prev)->next = (*curr)->next;
			free((*curr)->content);
			free(*curr);
			return (0);
		}
		*prev = *curr;
		*curr = (*curr)->next;
	}
	return (1);
}

static int				ft_freefdlist(int fd, t_list **toplist)
{
	t_list		*prev;
	t_list		*curr;
	t_list		*tmp;

	prev = *toplist;
	curr = (*toplist)->next;
	if (fd && *toplist && ((t_env*)(*toplist)->content)->fd == fd)
	{
		tmp = *toplist;
		*toplist = (*toplist)->next;
		free(tmp->content);
		free(tmp);
		return (0);
	}
	if (ft_freefdlist2(fd, &prev, &curr) == 0)
		return (0);
	return (0);
}

static t_list			*get_fdlist(int fd, t_list **toplist)
{
	t_env		*env;
	t_list		*tmplist;

	tmplist = *toplist;
	while (tmplist)
	{
		if (((t_env*)tmplist->content)->fd == fd)
		{
			return (tmplist);
		}
		tmplist = tmplist->next;
	}
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->fd = fd;
	env->ret = 0;
	env->index = 0;
	if (!(tmplist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmplist->content = env;
	tmplist->content_size = sizeof(env);
	ft_lstadd(toplist, tmplist);
	return (tmplist);
}

int						get_next_line(int const fd, char **line)
{
	static t_list	*toplist = NULL;
	t_env			*env;

	if (line)
		*line = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	if (!(env = (t_env*)get_fdlist(fd, &toplist)->content))
		return (-1);
	if (env->index)
	{
		if (ft_concat(line, &env))
			return (1);
	}
	while ((env->ret = read(env->fd, env->buf, BUFF_SIZE)))
	{
		if (env->ret == -1)
			return (-1);
		if (ft_concat(line, &env))
			return (1);
	}
	ft_freefdlist(fd, &toplist);
	return (0);
}
