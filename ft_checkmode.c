/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:41:24 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 20:44:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_checkmode(char *line)
{
	while(*line)
	{
		if(*line == ',')
			return (1);
		line++;
	}
	return (0);
}

