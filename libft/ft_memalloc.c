/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:40:24 by syusof            #+#    #+#             */
/*   Updated: 2014/11/13 08:35:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*mem;
	size_t		i;

	if (size == 0)
		return (0);
	if ((mem = (char*)malloc(sizeof(char) * size)))
	{
		i = 0;
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
		return (mem);
	}
	return (NULL);
}
