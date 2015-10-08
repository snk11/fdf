/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:46:25 by syusof            #+#    #+#             */
/*   Updated: 2015/05/06 16:23:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] && (size_t)i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (size_t)(i + j) < n)
		{
			if ((j + 1) != (int)ft_strlen(s2))
				j++;
			else
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
