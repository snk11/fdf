/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 08:32:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_read_map0(char *file, t_env2 *env2)
{
	char	*line;
	int		fd;

//	fd = open(file, O_RDONLY);
//	if(get_next_line(fd,&line) > 0)
//	{
//		if (ft_checkmode(line) == 1)
		{
			ft_read_map1(file, env2);
			env2->readmode = 1;
		}
//		else
//		{
//			ft_read_map2(file, env2);
//			env2->readmode = 2;
//		}
//	}
}
