/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 11:12:39 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 18:04:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_env2 *env2)
{
	env2->nb_lines = 0;
	env2->offx = 0;
	env2->offy = 0;
	env2->coeff = 0;
	env2->color = 0xFF0000;
	env2->i = 0;
	env2->error = 0;
	env2->readmode = 0;
	env2->maxx = 0;
	env2->minx = 0;
	env2->maxy = 0;
	env2->miny = 0;
}

void	ft_init2(t_para *para1)
{
	para1->dx = 0;
	para1->dy = 0;
	para1->sx = 0;
	para1->sy = 0;
	para1->err = 0;
	para1->e2 = 0;
}
