/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:25:17 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 15:28:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_checkdigit(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (!(s[i + 1]))
				return (0);
			if ((i != 0 && (s[i - 1] != ' ' && s[i - 1] != '\t'))
					|| (s[i + 1] && !ft_isdigit(s[i + 1])))
				return (0);
		}
		else if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int		ft_checkdigit2(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != ',')
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (!(s[i + 1]))
				return (0);
			if ((i != 0 && (s[i - 1] != ' ' && s[i - 1] != '\t'))
					|| (s[i + 1] && !ft_isdigit(s[i + 1])))
				return (0);
		}
		else if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '\t' && s[i])
			return (0);
		i++;
	}
	return (1);
}
