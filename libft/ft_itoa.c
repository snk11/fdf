/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:13:11 by syusof            #+#    #+#             */
/*   Updated: 2014/11/12 17:03:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countdigit(int n)
{
	int		i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		itoa_neg(char *str, int n, int i)
{
	while (i > 0)
	{
		str[1 + i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[0] = '-';
}

static void		itoa_pos(char *str, int n, int i)
{
	while (i > 0)
	{
		str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == INT_MIN)
	{
		str = ft_strnew(9);
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (n < 0 && n != INT_MIN)
	{
		n = -n;
		i = ft_countdigit(n);
		str = ft_strnew(1 + i + 1);
		itoa_neg(str, n, i);
	}
	else
	{
		i = ft_countdigit(n);
		str = ft_strnew(i + 1);
		itoa_pos(str, n, i);
	}
	return (str);
}
