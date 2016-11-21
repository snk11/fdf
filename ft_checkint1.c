/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkint1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:09:18 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 12:05:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_checkint_p2_p1_p7(char *s1)
{
	s1++;
	if (*s1 == '7')
		return (ft_checkint_p2_p1_p42(s1));
	else if (*s1 > '7')
		return (0);
	return (1);
}

int		ft_checkint_p2_p1_p42(char *s1)
{
	s1++;
	if (*s1 == '4')
		return (ft_checkint_p2_p1_p8(s1));
	else if (*s1 > '4')
		return (0);
	return (1);
}

int		ft_checkint_p2_p1_p8(char *s1)
{
	s1++;
	if (*s1 == '8')
		return (ft_checkint_p2_p1_p3(s1));
	else if (*s1 > '8')
		return (0);
	return (1);
}

int		ft_checkint_p2_p1_p3(char *s1)
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
				if (*s1 == '8')
				{
				}
				else if (*s1 > '8')
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

int		ft_checkint_p2_p2(char *s1)
{
	s1++;
	if (*s1 == '2')
		return (ft_checkint_p2_p2_p1(s1));
	else if (*s1 > '2')
		return (0);
	return (1);
}
