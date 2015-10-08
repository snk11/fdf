/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 20:06:19 by syusof            #+#    #+#             */
/*   Updated: 2014/11/19 02:14:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*curlst;

	curlst = (t_list*)malloc(sizeof(t_list));
	if (curlst == NULL)
		return (NULL);
	if (content == NULL)
	{
		curlst->content = NULL;
		curlst->content_size = 0;
	}
	else
	{
		curlst->content = malloc(sizeof(content));
		if (curlst->content == NULL)
			return (NULL);
		curlst->content = ft_memmove(curlst->content, content, content_size);
		curlst->content_size = content_size;
	}
	curlst->next = NULL;
	return (curlst);
}
