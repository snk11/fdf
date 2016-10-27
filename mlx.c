/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 23:44:16 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 09:23:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int			expose_hook1(t_env2 *env2)
{
	mlx_clear_window(env2->mlx, env2->win);
	draw1(env2);
	return (0);
}
