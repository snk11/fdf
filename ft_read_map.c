/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 16:44:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_getpoint(char *line, t_env2 *env2, int j)
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
			ft_getpoint2(env2, j, k);
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

void			ft_getpoint2(t_env2 *env2, int j, int k)
{
	((env2)->coord)[j][k].x = k;
	((env2)->coord)[j][k].y = j;
}

int				ft_get_col(char *line, t_env2 *env2, int i)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (line[k] && env2->error == 0)
	{
		if (ft_isdigit(line[k]) && line[k] != '+' && line[k] != '-')
		{
			while (line[k] && ft_isdigit(line[k]) && line[k] != '+'
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

void			ft_read_map0(char *file, t_env2 *env2)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if(get_next_line(fd,&line) > 0)
	{
		if (ft_checkmode(line) == 1)
		{
			ft_read_map1(file, env2);
			env2->readmode = 1;
		}
		else
		{
			ft_read_map2(file, env2);
			env2->readmode = 2;
		}
	}
}
