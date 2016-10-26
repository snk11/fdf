/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:57:25 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 20:02:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_print_line2(t_env2 *env2, t_coord coord1, t_coord coord2)
{
	t_para	para1;

	para1.x = coord1.x ;
	para1.y = coord1.y ;
	para1.dx = coord2.x -coord1.x  ;
	para1.dy = coord2.y - coord1.y;
	para1.xinc = ( para1.dx > 0 ) ? 1 : -1 ;
	para1.yinc = ( para1.dy > 0 ) ? 1 : -1 ;
	para1.dx = abs(para1.dx) ;
	para1.dy = abs(para1.dy) ;
	mlx_pixel_put((env2)->mlx, (env2)->win, OX +env2->offx
				   + para1.x, OY +env2->offy + para1.y, env2->color);
	if ( para1.dx > para1.dy )
	{
		para1.cumul = para1.dx / 2 ;
		para1.i = 1;
		while (  para1.i <= para1.dx )
		{
			para1.x += para1.xinc ;
			para1.cumul += para1.dy ;
			if ( para1.cumul >= para1.dx )
			{
				para1.cumul -= para1.dx ;
				para1.y += para1.yinc ;
			}
			mlx_pixel_put((env2)->mlx, (env2)->win, OX +env2->offx
				   + para1.x, OY +env2->offy + para1.y, env2->color);
			para1.i++;
		}
	}
	else 
	{
		para1.cumul = para1.dy / 2 ;
		para1.i = 1;
		while (para1.i <= para1.dy)
		{
			para1.y += para1.yinc ;
			para1.cumul += para1.dx ;
			if ( para1.cumul >= para1.dy ) 
			{
				para1.cumul -= para1.dy ;
				para1.x += para1.xinc ; 
			}
			mlx_pixel_put((env2)->mlx, (env2)->win, OX +env2->offx
				   + para1.x, OY +env2->offy + para1.y, env2->color);
			para1.i++;
		} 
	}
				/*
				   ft_init2(&para1);
				   para1.dx = ft_abs(coord2.x - coord1.x);
				   para1.dy = ft_abs(coord2.y - coord1.y);
				   para1.sx = coord1.x < coord2.x ? 1 : -1;
				   para1.sy = coord1.y < coord2.y ? 1 : -1;
				   para1.err = (para1.dx > para1.dy ? para1.dx : -(para1.dy)) / 2;
				   while (coord1.x != coord2.x && coord1.y != coord2.y)
				   {
				   mlx_pixel_put((env2)->mlx, (env2)->win, OX +env2->offx
				   + coord1.x, OY +env2->offy + coord1.y, env2->color);
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
				   */
				return (0);
}

void		draw2(t_env2 *env2)
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
			coord2 = get_coord(env2, env2->coord[p][q + 1], &ft_iso);
			ft_print_line2(env2, coord1, coord2);
			coord2 = get_coord(env2, env2->coord[p + 1][q], &ft_iso);
			ft_print_line2(env2, coord1, coord2);
			q++;
		}
		p++;
	}
	draw22(env2);
}

void		draw22(t_env2 *env2)
{
	t_coord		coord1;
	t_coord		coord2;
	int			p;
	int			q;

	p = 0;
	while (p < env2->nb_lines - 1)
	{
		coord1 = get_coord(env2, env2->coord[p][env2->col[p] - 1], &ft_iso);
		coord2 = get_coord(env2, env2->coord[p + 1][env2->col[p] - 1], &ft_iso);
		ft_print_line2(env2, coord1, coord2);
		p++;
	}
	q = 0;
	while (q < env2->col[p] - 1)
	{
		coord1 = get_coord(env2, env2->coord[p][q], &ft_iso);
		coord2 = get_coord(env2, env2->coord[p][q + 1], &ft_iso);
		ft_print_line2(env2, coord1, coord2);
		q++;
	}
}

