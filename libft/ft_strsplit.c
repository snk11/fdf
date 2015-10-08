/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:54:46 by syusof            #+#    #+#             */
/*   Updated: 2015/05/06 15:17:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_nb_words(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s && s[i] && c)
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			nb++;
		}
	}
	return (nb);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		start;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * ft_count_nb_words(s, c) + 1)))
		return (NULL);
	while (s && s[i] && c)
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[j] = ft_strsub(s, start, i - start);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
