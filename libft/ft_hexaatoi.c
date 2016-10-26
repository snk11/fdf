/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaatoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:28:15 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 17:25:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, int p)
{
	int	result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result = result * n;
		p--;
	}
	return (result);
}

int		ft_hexaatoi(char *s)
{
	int	len;
	int	res;
	int	i;

	len = ft_strlen(s);
	res = 0;
	i = 0;
	while(*s)
	{
		if(ft_isalpha(*s))
		{
			if(*s >= 97)
				i = *s - 97 + 10;
			else
				i = *s - 65 + 10;
		}
		else
			i = *s - 48;
		res = res + i * ft_pow(16,len - 1);
		len--;
		s++;
	}
	return (res);
}
