/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 23:44:16 by syusof            #+#    #+#             */
/*   Updated: 2015/05/29 15:23:53 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

/*
static int get_iso_x(int y, int x, int z)
{
	return (0.5 * (x - y));
}


static int get_iso_y(int y, int x, int z)
{
	return (- z + 0.5 / 2 * x + 0.5 / 2 * y);
}
*/


static	t_coord		get_coord_iso(t_env2 *env2, t_coord coord1, t_coord (*f)(int, int, int))
{
	t_coord		coord_mod;

	coord_mod.x = (OX + coord1.x * GAP_X);
	coord_mod.y = (OY + coord1.y * GAP_Y);
	coord_mod.z = coord1.z;
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


static int ft_print_line(t_env2 *env2,t_coord coord1, t_coord coord2)
{

	int dx = abs(coord2.x - coord1.x);
	int dy = abs(coord2.y - coord1.y);
	int sx = coord1.x < coord2.x ? 1 : -1;
	int sy = coord1.y < coord2.y ? 1 : -1;
	int err = (dx>dy ? dx : -dy) / 2;
	int e2;

	while(coord1.x != coord2.x && coord1.y != coord2.y)
	{
		mlx_pixel_put((env2)->mlx, (env2)->win,OX + coord1.x, OY + coord1.y, 0xFF0000);
		e2 = err;
		if (e2 > -dx )
		{
			err -= dy;
			coord1.x += sx;
		}
		if (e2< dy)
		{
			err += dx;
			coord1.y += sy;
		}
	}
	return (0);
}

 # include <stdio.h>

static void draw(t_env2 *env2)
{

/*
	int x1;
	int y1;
	int x2;
	int y2;
	int i;
	int i2;
	int col;
	int nb_lines;
	int max;

	int a;
	int b;
	int c;
*/
/*
	t_coord		coord1;
	t_coord		coord2;
	int p;
	int q;
	p = 0;
	q = 1;
	while( p < env2->nb_lines && !(p = 0))
	{
		while (p < env2->col[p])
		{
			coord1 = get_coord_iso(env2, env2->coord[p][q - 1], &ft_iso);
			if (q < env2->col[p])
			{
				coord2 = get_coord_iso(env2, env2->coord[p][q], &ft_iso);
				ft_print_line(env2, coord1, coord2);
			}
				if (p < (env2->nb_lines) && q < env2->col[p])
			{
				coord2 = get_coord_iso(env2, env2->coord[p][q], &ft_iso);
				ft_print_line(env2, coord1, coord2);
			}
		}
	}
*/


	t_coord		coord1;
	t_coord		coord2;
	int p;
	int q;
	p = 0;
	while(p < env2->nb_lines)
	{
		q = 1;
		while (q < env2->col[p])
		{
			coord1 = get_coord_iso(env2, env2->coord[p][q - 1], &ft_iso);
			printf("%d%d: %d ",p,q,(env2->coord[p][q-1]).z);
			if (q < env2->col[p])
			{
				coord2 = get_coord_iso(env2, env2->coord[p][q], &ft_iso);
				ft_print_line(env2, coord1, coord2);
			}
			if (p < (env2->nb_lines) && q < env2->col[p])
			{
				coord2 = get_coord_iso(env2, env2->coord[p + 1][q], &ft_iso);
				ft_print_line(env2, coord1, coord2);
			}
			q++;
		}
		printf("\n");
		p++;
	}


/*
	col = (env2)->col;
	nb_lines = (env2)->nb_lines;
	max = col * nb_lines;
	i = max - 1;
	while (i > 0)
	{
		if (i % col > 0)
		{
			i2 = i - 1;
			x1 = get_iso_x(i / col * GAP_X, i % col * GAP_Y, (env2)->z[i] * S_Z);
			y1 = get_iso_y(i / col * GAP_X, i % col * GAP_Y, (env2)->z[i] * S_Z);
			x2 = get_iso_x(i2 / col * GAP_X, i2 % col * GAP_Y, (env2)->z[i2] * S_Z);
			y2 = get_iso_y(i2 / col * GAP_X, i2 % col * GAP_Y, (env2)->z[i2] * S_Z);
			ft_print_line(env2, x1, y1, x2, y2);

			a = i / col * GAP_X;
			b = i % col * GAP_Y;
			c =(env2)->z[i];
		}

		if (i / col > 0)
		{
			i2 = i - col;
			x1 = get_iso_x(i / col * GAP_X, i % col * GAP_Y, (env2)->z[i] * S_Z);
			y1 = get_iso_y(i / col * GAP_X, i % col * GAP_Y, (env2)->z[i] * S_Z);
			x2 = get_iso_x(i2 / col * GAP_X, i2 % col * GAP_Y, (env2)->z[i2] * S_Z);
			y2 = get_iso_y(i2 / col * GAP_X, i2 % col * GAP_Y, (env2)->z[i2] * S_Z);
			ft_print_line(env2, x1, y1, x2, y2);
		}
		i--;
	}
}
*/

}

int		key_hook(int keycode, t_env2 *env2)
{
	if (keycode == 53)
		exit(0);
	return(0);
}

int		expose_hook(t_env2 *env2)
{
	draw(env2);
	return (0);
}
