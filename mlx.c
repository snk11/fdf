/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 23:44:16 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 09:17:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
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
*/
int			key_hook1(int keycode, t_env2 *env2)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		env2->offx -= 30;
	if (keycode == 124)
		env2->offx += 30;
	if (keycode == 125)
		env2->offy += 30;
	if (keycode == 126)
		env2->offy -= 30;
	if (keycode == 69)
		env2->coeff += 1;
	if (keycode == 78)
	{
		if ((env2->coeff - 1) > 0)
			env2->coeff -= 1;
	}
	key_hook3(keycode, env2);
	expose_hook1(env2);
	return (0);
}

void		key_hook3(int keycode, t_env2 *env2)
{
	if (keycode == 8)
	{
		if (env2->i < 5)
		{
			if (env2->i == 0)
				env2->color = 0x00FFFF;
			else if (env2->i == 1)
				env2->color = 0x008000;
			else if (env2->i == 2)
				env2->color = 0xFFFF00;
			else if (env2->i == 3)
				env2->color = 0x0000FF;
			else if (env2->i == 4)
				env2->color = 0xFF00FF;
			(env2->i)++;
		}
		else
		{
			env2->color = 0xFF0000;
			env2->i = 0;
		}
	}
}
/*
int			key_hook2(int keycode, t_env2 *env2)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		env2->offx -= 30;
	if (keycode == 124)
		env2->offx += 30;
	if (keycode == 125)
		env2->offy += 30;
	if (keycode == 126)
		env2->offy -= 30;
	if (keycode == 69)
		env2->coeff += 1;
	if (keycode == 78)
	{
		if ((env2->coeff - 1) > 0)
			env2->coeff -= 1;
	}
	key_hook3(keycode, env2);
	expose_hook2(env2);
	return (0);
}
*/
int			expose_hook1(t_env2 *env2)
{
	mlx_clear_window(env2->mlx, env2->win);
	draw1(env2);
	return (0);
}
/*
int			expose_hook2(t_env2 *env2)
{
	mlx_clear_window(env2->mlx, env2->win);
	draw2(env2);
	return (0);
}
*/
