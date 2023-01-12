/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:19:10 by gson              #+#    #+#             */
/*   Updated: 2021/05/17 20:03:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*cur;

	if (!lst)
		return (0);
	newlist = ft_lstnew(f(lst->content));
	lst = lst->next;
	cur = newlist;
	while (lst != NULL)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (cur == NULL)
		{
			ft_lstclear(&cur, del);
			return (newlist);
		}
		lst = lst->next;
		cur = cur->next;
	}
	return (newlist);
}
