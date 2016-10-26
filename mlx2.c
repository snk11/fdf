/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 12:54:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 13:40:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env2 *env2)
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
			ft_print_line(env2, coord1, coord2);
			coord2 = get_coord(env2, env2->coord[p + 1][q], &ft_iso);
			ft_print_line(env2, coord1, coord2);
			q++;
		}
		p++;
	}
	draw2(env2);
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
		coord1 = get_coord(env2, env2->coord[p][env2->col[p] - 1], &ft_iso);
		coord2 = get_coord(env2, env2->coord[p + 1][env2->col[p] - 1], &ft_iso);
		ft_print_line(env2, coord1, coord2);
		p++;
	}
	q = 0;
	while (q < env2->col[p] - 1)
	{
		coord1 = get_coord(env2, env2->coord[p][q], &ft_iso);
		coord2 = get_coord(env2, env2->coord[p][q + 1], &ft_iso);
		ft_print_line(env2, coord1, coord2);
		q++;
	}
}

void		key_hook2(int keycode, t_env2 *env2)
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
