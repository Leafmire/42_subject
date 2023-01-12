/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:00:12 by gson              #+#    #+#             */
/*   Updated: 2022/08/22 21:59:56 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last;

	if (lst == NULL || new_lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_lst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_lst;
}
