/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 05:39:12 by syusof            #+#    #+#             */
/*   Updated: 2014/11/19 00:37:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*curlst;
	t_list		*nextlst;

	if (alst && del)
	{
		curlst = *alst;
		while (curlst && del)
		{
			nextlst = curlst->next;
			del(curlst->content, curlst->content_size);
			free(curlst);
			curlst = nextlst;
		}
		*alst = NULL;
	}
}
