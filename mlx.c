/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 23:44:16 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 11:36:59 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_coord	get_coord(t_env2 *e2, t_coord c1, t_coord (*f)(int, int, int))
{
	t_coord		coord_mod;

	coord_mod.x = c1.x * GAP_X * e2->coeff;
	coord_mod.y = c1.y * GAP_Y * e2->coeff;
	coord_mod.z = c1.z * S_Z * e2->coeff;
	coord_mod = (f)(coord_mod.x, coord_mod.y, coord_mod.z);
	return (coord_mod);
}

static	t_coord		ft_iso(int x, int y, int z)
{
	t_coord		coord1;

	coord1.x = 0.5 * x - 0.5 * y;
	coord1.y = -z + 0.5 / 2 * x + 0.5 / 2 * y;
	coord1.z = z;
	return (coord1);
}

static int ft_print_line(t_env2 *env2, t_coord coord1, t_coord coord2)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;

	dx = ft_abs(coord2.x - coord1.x);
	dy = ft_abs(coord2.y - coord1.y);
	sx = coord1.x < coord2.x ? 1 : -1;
	sy = coord1.y < coord2.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (coord1.x != coord2.x && coord1.y != coord2.y)
	{
		mlx_pixel_put((env2)->mlx, (env2)->win, OX + env2->offx + coord1.x, OY + env2->offy + coord1.y, env2->color);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			coord1.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			coord1.y += sy;
		}
	}
	return (0);
}

static void draw(t_env2 *env2)
{
	t_coord		coord1;
	t_coord		coord2;
	int			p;
	int			q;

	p = 0;
	while (p < env2->nb_lines - 1)
	{
		q = 0;
		while (q < (env2->col[p]) - 1)
		{
			coord1 = get_coord(env2, env2->coord[p][q], &ft_iso);
//			if (q < env2->col[p])
			{
				coord2 = get_coord(env2, env2->coord[p][q + 1], &ft_iso);
				ft_print_line(env2, coord1, coord2);
			}
//			if (p < ((env2->nb_lines) - 1) && q < env2->col[p])
			{
				coord2 = get_coord(env2, env2->coord[p + 1][q], &ft_iso);
				ft_print_line(env2, coord1, coord2);
			}
			q++;
		}
		p++;
	}
	p = 0;
//	printf("nb lines = %d\n",env2->nb_lines);
	while (p < env2->nb_lines - 1)
	{
		coord1 = get_coord(env2, env2->coord[p][env2->col[p] - 1], &ft_iso);
		coord2 = get_coord(env2, env2->coord[p + 1][env2->col[p] - 1], &ft_iso);
		ft_print_line(env2, coord1, coord2);
		p++;
	}
//	printf("p = %d\n",p);
	q = 0;
	while (q < env2->col[p] - 1)
	{
		coord1 = get_coord(env2, env2->coord[p][q], &ft_iso);
		coord2 = get_coord(env2, env2->coord[p][q + 1], &ft_iso);
		ft_print_line(env2, coord1, coord2);
		q++;
	}
}

int		key_hook(int keycode, t_env2 *env2)
{
	//	printf("keycode = %d\n",keycode);
	
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
	if (keycode == 8)
	{
		if (env2->i < 5)
		{
			if(env2->i == 0)
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

	expose_hook(env2);
	return (0);
}

int		expose_hook(t_env2 *env2)
{
	mlx_clear_window(env2->mlx, env2->win);
	draw(env2);
	return (0);
}
