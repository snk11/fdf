/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:04:30 by syusof            #+#    #+#             */
/*   Updated: 2017/02/08 10:45:16 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countdigit(long long n)
{
	long long int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		itoa_neg(char *str, long long int n, long long int i)
{
	while (i > 0)
	{
		str[1 + i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[0] = '-';
}

static void		itoa_pos(char *str, long long int n, long long int i)
{
	while (i > 0)
	{
		str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

char			*ft_lldtoa(long long int n)
{
	char				*str;
	long long int		i;

	if (n == LLONG_MIN)
	{
		str = ft_strnew(21 + 1);
		str = ft_strcpy(str, "-9223372036854775808");
		return (str);
	}
	if (n < 0 && n != LLONG_MIN)
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
