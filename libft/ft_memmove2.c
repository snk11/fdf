/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 04:10:20 by syusof            #+#    #+#             */
/*   Updated: 2016/11/18 18:32:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove2(char *src)
{
	int		i;
	int		n;
	char	*temp;

	n = ft_strlen(src);
	temp = (char*)malloc(sizeof(char) * n + 1);
	i = 0;
	while (i <= n)
	{
		temp[i] = src[i];
		i++;
	}
	return (temp);
}
