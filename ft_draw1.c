/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:57:03 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 10:41:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		coord2 = get_coord1(env2, env2->doub1[p + 1][env2->col[p] - 1],
				&ft_iso1);
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
