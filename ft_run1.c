/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:01:10 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 13:44:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_run1(int fd, char *file, t_env2 *env2)
{
	int		j;
	char	*line;

	line = NULL;
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line)
		{
			j++;
			(env2)->nb_lines = j;
		}
		ft_free(&line);
	}
	ft_free(&line);
	close(fd);
	(env2)->doub1 = (t_doub**)malloc(sizeof(t_doub*) * j);
	fd = open(file, O_RDONLY);
	(env2)->col = (int*)malloc(sizeof(int) * j);
	ft_read_map11(file, env2, line);
}
