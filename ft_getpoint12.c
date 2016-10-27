/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpoint12.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:28:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 10:06:56 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_getpoint12(t_env2 *env2, char *line, int j, t_ca *c1)
{
	while (line[c1->i] && env2->error == 0 && line[c1->i] != '\t' && line[c1->i] != ' ')
	{
		if (ft_isdigit(line[c1->i]) && line[c1->i] != '+' && line[c1->i] != '-')
		{
			c1->start = c1->i;
			while (line[c1->i] && ft_isdigit(line[c1->i]) && line[c1->i] != '+'
					&& line[c1->i] != '-')
				c1->i++;
			ft_getpoint3(env2, j, c1->k);
			c1->tmp = ft_atoi(ft_strsub(line, c1->start, c1->i - c1->start));
			((env2)->doub1)[j][c1->k].z = c1->tmp;
		}
		else
			env2->error = 1;
	}
}
