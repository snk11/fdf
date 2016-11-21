/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functiond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 10:09:21 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 13:39:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_doub		get_coord1(t_env2 *e2, t_doub c1, t_doub (*f)(int, int, int))
{
	t_doub		coord_mod;

	coord_mod.x = c1.x * GAP_X * e2->coeff;
	coord_mod.y = c1.y * GAP_Y * e2->coeff;
	coord_mod.z = c1.z * S_Z * e2->coeff;
	coord_mod = (f)(coord_mod.x, coord_mod.y, coord_mod.z);
	return (coord_mod);
}

t_doub		ft_iso1(int x, int y, int z)
{
	t_doub		coord1;

	coord1.x = 0.5 * x - 0.5 * y;
	coord1.y = -z + 0.5 / 2 * x + 0.5 / 2 * y;
	coord1.z = z;
	return (coord1);
}

void		ft_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}
