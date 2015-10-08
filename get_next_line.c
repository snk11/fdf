/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 11:25:15 by syusof            #+#    #+#             */
/*   Updated: 2015/01/06 01:08:16 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"


static int		ft_concat(char **line, t_env **env)
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
	ft_strcat(str, ft_strsub((*env)->buf, (*env)->index, i - (*env)->index));
	*line = str;
	if (i < (*env)->ret)
	{
		(*env)->index = i + 1;
		return (1);
	}
		return (0);
}


/*
static int		ft_concat(char **line, t_env **env)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = (*env)->index;
	while (i < (*env)->ret && (*env)->buf[i] != '\n')
	{
		i++;
	}
	tmp = ft_strsub((*env)->buf, (*env)->index, i - (*env)->index);
	tmp2 = *line;
	if (line && *line)
		*line = ft_strjoin(*line, tmp);
	else
		*line = ft_strdup(tmp);
	free(tmp);
	free(tmp2);
	if (i < (*env)->ret)
	{
		(*env)->index = i + 1;
		return (1);
	}
	return (0);
}
*/

static int	ft_freefdlist(int fd, t_list **downlist)
{
	t_list		*prev;
	t_list		*curr;
	t_list		*tmp;

	prev = *downlist;
	curr = (*downlist)->next;
	if (*downlist && ((t_env*)(*downlist)->content)->fd == fd)
	{
		tmp = *downlist;
		*downlist = (*downlist)->next;
		free(tmp);
		return (0);
	}
	while (prev && curr)
	{
		if (((t_env*)(curr)->content)->fd == fd)
		{
			prev->next = curr->next;
			free(curr);
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

/*
static t_list	*get_fdlist2(int fd, t_list *downlist)
{
	t_env	*env;

	if(!downlist)
		return (NULL);
	while (downlist)
	{
		env = (t_env*)downlist->content;
		if (env && env->fd == fd)
			return (downlist);
		downlist = downlist->next;
	}
	return (NULL);
}
*/

static t_list		*get_fdlist(int fd, t_list **downlist)
{
	t_env		*env;
	t_list		*tmp;

	tmp = *downlist;
	while (tmp)
	{
		if (((t_env*)tmp->content)->fd == fd)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
/*
	if ((tmp = get_fdlist2(fd,*downlist)))
	{
		printf("g");
		return (tmp);
	}
*/
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->fd = fd;
	env->ret = 0;
	env->index = 0;
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = env;
	tmp->content_size = sizeof(env);
	ft_lstadd(downlist, tmp);
	return (tmp);
}


int		get_next_line(int const fd, char **line)
{
	static t_list	*downlist = NULL;
	t_env			*env;

	ft_strdel(line);
//	downlist = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE == 0 || BUFF_SIZE > 8192)
		return (-1);
	if(!(env = (t_env*)get_fdlist(fd,&downlist)->content))
		return (-1);
	if(env->index)
	{
		if (ft_concat(line, &env))
			return (1);
	}
	env->index = 0;
	while ((env->ret = read(env->fd, env->buf, BUFF_SIZE)))
	{
		if (env->ret == -1)
			return (-1);
		if (ft_concat(line, &env))
			return (1);
	}
	ft_freefdlist(fd, &downlist);
	return (0);
}
