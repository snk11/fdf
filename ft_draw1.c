/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:57:03 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 17:08:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_print_line1(t_env2 *env2, t_doub coord1, t_doub coord2)
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

void		draw1(t_env2 *env2)
{
	t_doub		coord1;
	t_doub		coord2;
	int			p;
	int			q;

	p = 0;
	while (p < env2->nb_lines - 1)
	{
		q = 0;
		while (q < (env2->col[p]) - 1)
		{
			coord1 = get_coord1(env2, env2->doub1[p][q], &ft_iso1);
			coord2 = get_coord1(env2, env2->doub1[p][q + 1], &ft_iso1);
			ft_print_line1(env2, coord1, coord2);
			coord2 = get_coord1(env2, env2->doub1[p + 1][q], &ft_iso1);
			ft_print_line1(env2, coord1, coord2);
			q++;
		}
		p++;
	}
	draw11(env2);
}

void		draw11(t_env2 *env2)
{
	t_doub		coord1;
	t_doub		coord2;
	int			p;
	int			q;

	p = 0;
	while (p < env2->nb_lines - 1)
	{
		coord1 = get_coord1(env2, env2->doub1[p][env2->col[p] - 1], &ft_iso1);
		coord2 = get_coord1(env2, env2->doub1[p + 1][env2->col[p] - 1], &ft_iso1);
		ft_print_line1(env2, coord1, coord2);
		p++;
	}
	q = 0;
	while (q < env2->col[p] - 1)
	{
		coord1 = get_coord1(env2, env2->doub1[p][q], &ft_iso1);
		coord2 = get_coord1(env2, env2->doub1[p][q + 1], &ft_iso1);
		ft_print_line1(env2, coord1, coord2);
		q++;
	}
}

