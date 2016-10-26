/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:18:46 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 13:42:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d;
	size_t		lendst;
	size_t		lensrc;

	if (dst && src)
	{
		lendst = ft_strlen(dst);
		lensrc = ft_strlen(src);
		if (size <= lendst)
			return (lensrc + size);
		else
		{
			d = size - lendst - 1;
			ft_strncat(dst, src, d);
			return (lendst + lensrc);
		}
	}
	return (0);
}
