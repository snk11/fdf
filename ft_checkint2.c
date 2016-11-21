/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkint2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:17:58 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 12:06:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_checkint_p2_p2_p1(char *s1)
{
	s1++;
	if (*s1 == '1')
		return (ft_checkint_p2_p2_p4(s1));
	else if (*s1 > '1')
		return (0);
	return (1);
}

int		ft_checkint_p2_p2_p4(char *s1)
{
	s1++;
	if (*s1 == '4')
		return (ft_checkint_p2_p2_p7(s1));
	else if (*s1 > '4')
		return (0);
	return (1);
}

int		ft_checkint_p2_p2_p7(char *s1)
{
	s1++;
	if (*s1 == '7')
		return (ft_checkint_p2_p2_p42(s1));
	else if (*s1 > '7')
		return (0);
	return (1);
}

int		ft_checkint_p2_p2_p42(char *s1)
{
	s1++;
	if (*s1 == '4')
		return (ft_checkint_p2_p2_p8(s1));
	else if (*s1 > '4')
		return (0);
	return (1);
}

int		ft_checkint_p2_p2_p8(char *s1)
{
	s1++;
	if (*s1 == '8')
		return (ft_checkint_p2_p2_p3(s1));
	else if (*s1 > '8')
		return (0);
	return (1);
}
