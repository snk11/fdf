/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpoint12.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:28:59 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 15:20:04 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_getpoint12(t_env2 *env2, char *line, int j, t_ca *c1)
{
	char	*s1;

	s1 = NULL;
	while (line[c1->i] && env2->error == 0 && line[c1->i] != '\t'
			&& line[c1->i] != ' ')
	{
		if (ft_checkint(&(line[c1->i])))
		{
			c1->start = c1->i;
			while (line[c1->i] && (ft_isdigit(line[c1->i]) || line[c1->i] == '+'
						|| line[c1->i] == '-'))
				c1->i++;
			ft_getpoint3(env2, j, c1->k);
			s1 = ft_strsub(line, c1->start, c1->i - c1->start);
			c1->tmp = ft_atoi(s1);
			ft_free(&s1);
			((env2)->doub1)[j][c1->k].z = c1->tmp;
			c1->k++;
		}
		else
			env2->error = 1;
	}
}

void			ft_getpoint3(t_env2 *env2, int j, int k)
{
	((env2)->doub1)[j][k].x = k;
	((env2)->doub1)[j][k].y = j;
}
