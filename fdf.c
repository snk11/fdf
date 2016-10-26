/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:52:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 11:54:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

int		main(int arc, char **arv)
{
	t_env2	*env2;

	if (!(env2 = (t_env2*)malloc(sizeof(t_env2))))
		return (-1);
	ft_init(env2);
	env2->mlx = mlx_init();
	env2->win = mlx_new_window(env2->mlx, 800, 800, "fdf");
	if (arc == 2)
		ft_read_map(arv[1], env2);
	mlx_key_hook(env2->win, key_hook, env2);
	mlx_expose_hook(env2->win, expose_hook, env2);
	mlx_loop(env2->mlx);
	return (1);
}
