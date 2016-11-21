/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:45:29 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 13:47:32 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_col1(char *line, t_env2 *env2, int i)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (line[k])
	{
		while (line[k] && (line[k] == '\t' || line[k] == ' '))
			k++;
		if (line[k] && line[k] != '\t' && line[k] != ' ')
		{
			while (line[k] && line[k] != '\t' && line[k] != ' ')
				k++;
			n++;
		}
	}
	((env2)->col)[i] = n;
	return (n);
}
