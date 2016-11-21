/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkint3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:18:47 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 12:06:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_checkint_p2_p2_p3(char *s1)
{
	s1++;
	if (*s1 == '3')
	{
		s1++;
		if (*s1 == '6')
		{
			s1++;
			if (*s1 == '4')
			{
				s1++;
				if (*s1 == '7')
				{
				}
				else if (*s1 > '7')
					return (0);
			}
			else if (*s1 > '4')
				return (0);
		}
		else if (*s1 > '6')
			return (0);
	}
	else if (*s1 > '3')
		return (0);
	return (1);
}

int		ft_checkint_p2(char *s1)
{
	if (*s1 == '2')
		return (ft_checkint_p2_p2_p1(s1));
	else if (*s1 > '2')
		return (0);
	return (1);
}
