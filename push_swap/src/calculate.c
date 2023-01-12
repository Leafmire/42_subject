/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:19 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 17:57:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	t_node	*cur;
	int		i;

	cur = stack->top;
	i = 0;
	while (cur != stack->tail)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

int	Max(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	else
		return (c);
}

int	Min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	else
		return (c);
}
