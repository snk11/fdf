/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:52:17 by syusof            #+#    #+#             */
/*   Updated: 2016/11/14 12:08:34 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int arc, char **arv)
{
	t_env2	*env2;

	if (!(env2 = (t_env2*)malloc(sizeof(t_env2))))
		return (-1);
	ft_init(env2);
	if (arc == 2)
		ft_read_map1(arv[1], env2);
	if (env2->error == 0 && arc == 2 && env2->dir == 0)
	{
		env2->mlx = mlx_init();
		env2->win = mlx_new_window(env2->mlx, 800, 800, "fdf");
		mlx_key_hook(env2->win, key_hook1, env2);
		mlx_expose_hook(env2->win, expose_hook1, env2);
		mlx_loop(env2->mlx);
	}
	else if (env2->error == 1)
		ft_putstr("error map\n");
	else
		ft_putstr("put a correct map entry please\n");
	return (1);
}
