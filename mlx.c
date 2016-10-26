/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 23:44:16 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 13:37:37 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		get_coord(t_env2 *e2, t_coord c1, t_coord (*f)(int, int, int))
{
	t_coord		coord_mod;

	coord_mod.x = c1.x * GAP_X * e2->coeff;
	coord_mod.y = c1.y * GAP_Y * e2->coeff;
	coord_mod.z = c1.z * S_Z * e2->coeff;
	coord_mod = (f)(coord_mod.x, coord_mod.y, coord_mod.z);
	return (coord_mod);
}

t_coord		ft_iso(int x, int y, int z)
{
	t_coord		coord1;

	coord1.x = 0.5 * x - 0.5 * y;
	coord1.y = -z + 0.5 / 2 * x + 0.5 / 2 * y;
	coord1.z = z;
	return (coord1);
}

int			ft_print_line(t_env2 *env2, t_coord coord1, t_coord coord2)
{
	t_para	para1;

	ft_init2(&para1);
	para1.dx = ft_abs(coord2.x - coord1.x);
	para1.dy = ft_abs(coord2.y - coord1.y);
	para1.sx = coord1.x < coord2.x ? 1 : -1;
	para1.sy = coord1.y < coord2.y ? 1 : -1;
	para1.err = (para1.dx > para1.dy ? para1.dx : -(para1.dy)) / 2;
	while (coord1.x != coord2.x && coord1.y != coord2.y)
	{
		mlx_pixel_put((env2)->mlx, (env2)->win, OX + env2->offx
				+ coord1.x, OY + env2->offy + coord1.y, env2->color);
		para1.e2 = para1.err;
		if (para1.e2 > -(para1.dx))
		{
			para1.err -= para1.dy;
			coord1.x += para1.sx;
		}
		if (para1.e2 < para1.dy)
		{
			para1.err += para1.dx;
			coord1.y += para1.sy;
		}
	}
	return (0);
}

int			key_hook(int keycode, t_env2 *env2)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		env2->offx -= 5;
	if (keycode == 124)
		env2->offx += 5;
	if (keycode == 125)
		env2->offy += 5;
	if (keycode == 126)
		env2->offy -= 5;
	if (keycode == 69)
		env2->coeff += 1;
	if (keycode == 78)
	{
		if ((env2->coeff - 1) > 0)
			env2->coeff -= 1;
	}
	key_hook2(keycode, env2);
	expose_hook(env2);
	return (0);
}

int			expose_hook(t_env2 *env2)
{
	mlx_clear_window(env2->mlx, env2->win);
	draw(env2);
	return (0);
}
