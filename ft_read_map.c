/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 11:55:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_getpoint(char *line, t_env2 *env2, int j)
{
	int		i;
	int		start;
	int		k;
	int		tmp;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) && line[i] != '+' && line[i] != '-')
		{
			start = i;
			while (line[i] && ft_isdigit(line[i]) && line[i] != '+'
				&& line[i] != '-')
				i++;
			((env2)->coord)[j][k].x = k;
			((env2)->coord)[j][k].y = j;
			tmp = ft_atoi(ft_strsub(line, start, i - start));
			((env2)->coord)[j][k].z = tmp;
			k++;
		}
		else if (line[i] == '\t' || line[i] == ' ')
			i++;
		else
			env2->error = 1;
	}
}

static	int		ft_get_col(char *line, t_env2 *env2, int i)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (line[k])
	{
		if (ft_isdigit(line[k]) && line[k] != '+' && line[k] != '-')
		{
			while (line[k] && ft_isdigit(line[k]) && line[k] != '+'
			&& line[k] != '-')
				k++;
			n++;
		}
		else if(line[k] == '\t' || line[k] == ' ')
		{
			k++;
		}
	}
	((env2)->col)[i] = n;
	return (n);
}

void			ft_read_map(char *file, t_env2 *env2)
{
	int		fd;
	char	*line;
//	int		i;
	int		j;
	int		c;

	c = 0;
	line = NULL;
//	if (!j)
		j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		j++;
		(env2)->nb_lines = j;
	}
	close(fd);
	(env2)->coord = (t_coord**)malloc(sizeof(t_coord*) * j);
	fd = open(file, O_RDONLY);
	(env2)->col = (int*)malloc(sizeof(int) * j);
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
