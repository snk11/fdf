/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:49:57 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 14:18:44 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_read_map1(char *file, t_env2 *env2)
{
	int		fd;
	int		c;

	c = 0;
	fd = open(file, O_DIRECTORY);
	if (fd == -1)
		env2->dir = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		env2->error = 2;
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	else if (fd != -1 && env2->dir == 0)
		ft_run1(fd, file, env2);
	else if (env2->dir == 1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(" is a directory\n", 2);
	}
}

void			ft_read_map11(char *file, t_env2 *env2, char *line)
{
	int		fd;
	int		j;
	int		c;

	fd = open(file, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		c = ft_get_col1(line, env2, j);
		((env2)->doub1)[j] = (t_doub*)malloc(sizeof(t_doub) * c);
		j++;
		ft_free(&line);
	}
	ft_free(&line);
	close(fd);
	ft_read_map111(file, env2, line);
}

void			ft_read_map111(char *file, t_env2 *env2, char *line)
{
	int		j;
	int		fd;

	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_getpoint1(line, env2, j);
		j++;
		ft_free(&line);
	}
	ft_free(&line);
	close(fd);
	(env2)->offx = 0;
	(env2)->offy = 0;
	(env2)->coeff = 2;
}

void			ft_getpoint1(char *line, t_env2 *env2, int j)
{
	t_ca	c1;

	ft_init3(&c1);
	while (line[c1.i] && env2->error == 0)
	{
		while (line[c1.i] && (line[c1.i] == ' ' || line[c1.i] == '\t'))
			c1.i++;
		if (ft_checkmode(&line[c1.i]) == 1)
		{
//			if (ft_isdigit(line[c1.i]) && line[c1.i] != '+'
//					&& line[c1.i] != '-')
//			{
				ft_getpoint11(env2, line, j, &c1);
//				c1.k++;
//			}
		}
		else if (ft_checkmode(&line[c1.i]) == 0)
		{
			ft_getpoint12(env2, line, j, &c1);
		}
		else
			env2->error = 1;
	}
}
