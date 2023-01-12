/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:27:05 by gson              #+#    #+#             */
/*   Updated: 2022/08/22 21:59:57 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (lst == NULL || new_lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_lst;
		return ;
	}
	new_lst->next = *lst;
	*lst = new_lst;
}
