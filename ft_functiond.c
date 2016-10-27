/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functiond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 10:09:21 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 10:48:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_print_line1(t_env2 *env2, t_doub coord1, t_doub coord2)
{
	t_para	para1;

	para1.x = coord1.x;
	para1.y = coord1.y;
	para1.dx = coord2.x - coord1.x;
	para1.dy = coord2.y - coord1.y;
	para1.xinc = (para1.dx > 0) ? 1 : -1;
	para1.yinc = (para1.dy > 0) ? 1 : -1;
	para1.dx = abs(para1.dx);
	para1.dy = abs(para1.dy);
	mlx_pixel_put((env2)->mlx, (env2)->win, OX + env2->offx
			+ para1.x, OY + env2->offy + para1.y, env2->color);
	if (para1.dx > para1.dy)
		ft_print_line11(env2, para1);
	else
		ft_print_line12(env2, para1);
	return (0);
}

void		ft_print_line11(t_env2 *env2, t_para para1)
{
	para1.cumul = para1.dx / 2;
	para1.i = 1;
	while (para1.i <= para1.dx)
	{
		para1.x += para1.xinc;
		para1.cumul += para1.dy;
		if (para1.cumul >= para1.dx)
		{
			para1.cumul -= para1.dx;
			para1.y += para1.yinc;
		}
		mlx_pixel_put((env2)->mlx, (env2)->win, OX + env2->offx
				+ para1.x, OY + env2->offy + para1.y, env2->color);
		para1.i++;
	}
}

void		ft_print_line12(t_env2 *env2, t_para para1)
{
	para1.cumul = para1.dy / 2;
	para1.i = 1;
	while (para1.i <= para1.dy)
	{
		para1.y += para1.yinc;
		para1.cumul += para1.dx;
		if (para1.cumul >= para1.dy)
		{
			para1.cumul -= para1.dy;
			para1.x += para1.xinc;
		}
		mlx_pixel_put((env2)->mlx, (env2)->win, OX + env2->offx
				+ para1.x, OY + env2->offy + para1.y, env2->color);
		para1.i++;
	}
}

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