/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 05:50:52 by gson              #+#    #+#             */
/*   Updated: 2021/11/20 06:02:33 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_goal	*lstnew(int y, int x)
{
	t_goal	*newlist;

	newlist = (t_goal *)malloc(sizeof(t_goal));
	newlist->is_collect = 0;
	newlist->y = y;
	newlist->x = x;
	newlist->next = NULL;
	return (newlist);
}

void	lstadd_back(t_goal **lst, t_goal *new)
{
	t_goal	*node;

	node = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

void	lstclear(t_goal **lst)
{
	t_goal	*node;

	node = *lst;
	if (lst || *lst)
	{
		while (*lst)
		{
			*lst = node->next;
			free(node);
			node = *lst;
		}
	}
}
