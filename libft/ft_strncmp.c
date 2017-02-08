/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:28:45 by syusof            #+#    #+#             */
/*   Updated: 2016/05/30 15:45:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (!(*s1 && *s2 && (unsigned char)*s1 == (unsigned char)*s2))
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
