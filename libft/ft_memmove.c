/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:52:52 by syusof            #+#    #+#             */
/*   Updated: 2014/11/11 23:49:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;
	char	*temp;

	temp = (char*)malloc(sizeof(char) * n);
	s1 = (char*)dest;
	s2 = (char*)src;
	i = 0;
	while (i < n)
	{
		temp[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s1[i] = temp[i];
		i++;
	}
	return (s1);
}
