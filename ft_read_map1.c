/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:49:57 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 17:28:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_read_map1(char *file, t_env2 *env2)
{
	int		fd;
	char	*line;
	int		j;
	int		c;

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
	(env2)->doub1 = (t_doub**)malloc(sizeof(t_doub*) * j);
	fd = open(file, O_RDONLY);
	(env2)->col = (int*)malloc(sizeof(int) * j);
	ft_read_map11(file, env2, line);
}

void		ft_read_map11(char *file, t_env2 *env2, char *line)
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
	}
	close(fd);
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_getpoint1(line, env2, j);
		j++;
	}
	close(fd);
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_getpoint1(line, env2, j);
		j++;
	}
	close(fd);
	(env2)->offx = 0;
	(env2)->offy = 0;
	(env2)->coeff = 2;
}



void			ft_getpoint1(char *line, t_env2 *env2, int j)
{
	int		i;
	int		start;
	int		k;
	int		tmp;

	i = 0;
	k = 0;
	while (line[i] && env2->error == 0)
	{
		if (ft_isdigit(line[i]) && line[i] != '+' && line[i] != '-')
		{
			start = i;
			while (line[i] && ft_isdigit(line[i]) && line[i] != '+'
				&& line[i] != '-')
				i++;
			ft_getpoint12(env2, j, k);
			tmp = ft_atoi(ft_strsub(line, start, i - start));
			((env2)->doub1)[j][k].z = tmp;
			if(line[i] == ',' && line[i+1] && line[i+1] == '0' && line[i+2] && line[i+2] == 'x')
			{
				
				i = i + 3;
				start = i;
				while (line[i]  && line[i] != '+'
					&& line[i] != '-' && (ft_isdigit(line[i]) || (line[i] >= 'a' && line[i] <= 'f' )|| (line[i] >= 'A' && line[i] <= 'F')))
					i++;
				if(start < i)
				{
					tmp = ft_hexaatoi(ft_strsub(line, start, i - start));
					((env2)->doub1)[j][k].color = tmp;
				}
			}
			k++;
		}
		else if (line[i] == '\t' || line[i] == ' ')
			i++;
		else
			env2->error = 1;
	}
}

void			ft_getpoint12(t_env2 *env2, int j, int k)
{
	((env2)->doub1)[j][k].x = k;
	((env2)->doub1)[j][k].y = j;
}

int				ft_get_col1(char *line, t_env2 *env2, int i)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (line[k] && env2->error == 0)
	{
		if (ft_isdigit(line[k]) && line[k] != '+' && line[k] != '-')
		{
			while (line[k] && (ft_isalnum(line[k]) || line[k] == ',' || line[k] == 'x')&& line[k] != '+'
			&& line[k] != '-')
				k++;
			n++;
		}
		else if (line[k] == '\t' || line[k] == ' ')
		{
			k++;
		}
		else
			env2->error = 1;
	}
	((env2)->col)[i] = n;
	return (n);
}