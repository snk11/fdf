/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 12:34:04 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 12:49:53 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_read_map2(char *file, t_env2 *env2, char *line)
{
	int		fd;
	int		j;
	int		c;

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
