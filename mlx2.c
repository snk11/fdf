/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 12:54:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 16:33:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
