/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:27:34 by syusof            #+#    #+#             */
/*   Updated: 2017/02/08 11:03:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int				i;
	unsigned int	max;
	char			*str;

	if (start > ft_strlen(s) || (start + len) > ft_strlen(s))
		return (0);
	i = 0;
	str = ft_strnew(len + 1);
	max = start + len;
	while (start <= max)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
