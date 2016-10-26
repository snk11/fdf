/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:23:08 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 17:09:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void            ft_read_map2(char *file, t_env2 *env2)
{
	int        fd;
	char    *line;
	int        j;
	int        c;

	c = 0;
	line = NULL;
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line)
		{
			j++;
			(env2)->nb_lines = j;
		}
	}
	close(fd);
	(env2)->coord = (t_coord**)malloc(sizeof(t_coord*) * j);
	fd = open(file, O_RDONLY);
	(env2)->col = (int*)malloc(sizeof(int) * j);
	ft_read_map22(file, env2, line);
}

void        ft_read_map22(char *file, t_env2 *env2, char *line)
{
	int        fd;
	int        j;
	int        c;

	fd = open(file, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		c = ft_get_col(line, env2, j);
		((env2)->coord)[j] = (t_coord*)malloc(sizeof(t_coord) * c);
		j++;
	}
	close(fd);
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_getpoint(line, env2, j);
		j++;
	}
	close(fd);
	(env2)->offx = 0;
	(env2)->offy = 0;
	(env2)->coeff = 2;
}
