/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 13:48:06 by syusof            #+#    #+#             */
/*   Updated: 2015/05/16 14:01:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fct1(t_list *lst, t_list **newlst, t_list *(*f)(t_list *elem))
{
	t_list		*nextlst;
	t_list		*flst;
	t_list		*newlst2;

	while (lst)
	{
		nextlst = lst->next;
		flst = f(lst);
		newlst2 = ft_lstnew(flst->content, flst->content_size);
		(*newlst)->next = newlst2;
		*newlst = newlst2;
		lst = nextlst;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*newlst;
	t_list		*nextlst;
	t_list		*flst;
	t_list		*newlst2;
	t_list		*firstlst;

	firstlst = NULL;
	newlst2 = NULL;
	flst = NULL;
	newlst = NULL;
	nextlst = lst->next;
	if (lst && f)
	{
		flst = f(lst);
		newlst = ft_lstnew(flst->content, flst->content_size);
		firstlst = newlst;
		lst = nextlst;
	}
	fct1(lst, &newlst, f);
	return (firstlst);
}
