/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:45:29 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 14:46:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_col1(char *line, t_env2 *env2, int i)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (line[k] && env2->error == 0)
	{
		if (ft_isdigit(line[k]) && line[k] != '+' && line[k] != '-')
		{
			while (line[k] && (ft_isalnum(line[k]) || line[k] == ','
						|| line[k] == 'x') && line[k] != '+' && line[k] != '-')
				k++;
			n++;
		}
		else if (line[k] == '\t' || line[k] == ' ')
		{
			k++;
		}
		else
			env2->error = 1;
	}
	((env2)->col)[i] = n;
	return (n);
}
