/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:03:37 by syusof            #+#    #+#             */
/*   Updated: 2017/01/24 11:37:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	if ((str = (char*)malloc(sizeof(char) * size)))
	{
		i = 0;
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return (str);
	}
	return (NULL);
}
