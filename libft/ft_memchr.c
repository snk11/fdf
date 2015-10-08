/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:17:47 by syusof            #+#    #+#             */
/*   Updated: 2015/05/16 13:31:54 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	str = (unsigned char*)s;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (str[i] == (unsigned char)c)
				return ((void*)(&str[i]));
			i++;
		}
	}
	return (NULL);
}
