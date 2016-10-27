/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpoint11.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:28:35 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 14:24:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_getpoint11(t_env2 *env2, char *line, int j, t_ca *c1)
{
	char	*s1;

	s1 = NULL;
	c1->start = c1->i;
	while (line[c1->i] && ft_isdigit(line[c1->i]) && line[c1->i] != '+'
			&& line[c1->i] != '-')
		c1->i++;
	ft_getpoint3(env2, j, c1->k);
	s1 = ft_strsub(line, c1->start, c1->i - c1->start);
	c1->tmp = ft_atoi(s1);
	ft_free(&s1);
	((env2)->doub1)[j][c1->k].z = c1->tmp;
	if (line[c1->i] == ',' && line[c1->i + 1] && line[c1->i + 1] == '0'
			&& line[c1->i + 2] && line[c1->i + 2] == 'x')
	{
		c1->i = c1->i + 3;
		c1->start = c1->i;
		while (line[c1->i] && line[c1->i] != '+'
				&& line[c1->i] != '-' && (ft_isdigit(line[c1->i])
					|| (line[c1->i] >= 'a' && line[c1->i] <= 'f')
					|| (line[c1->i] >= 'A' && line[c1->i] <= 'F')))
			c1->i++;
		if (c1->start < c1->i)
		{
			s1 = ft_strsub(line, c1->start, c1->i - c1->start);
			c1->tmp = ft_hexaatoi(s1);
			ft_free(&s1);
			((env2)->doub1)[j][c1->k].color = c1->tmp;
		}
	}
}
