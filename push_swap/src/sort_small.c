/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:15 by gson              #+#    #+#             */
/*   Updated: 2022/02/07 15:09:08 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_two(t_stack *a)
{
	if (a->top->num > a->top->next->num)
	{
		swap_stack(a, A);
		return ;
	}
	else
		return ;
}

void	push_swap_three(t_stack *a)
{
	int	max;
	int	min;

	max = Max(a->top->num, a->top->next->num, a->top->next->next->num);
	min = Min(a->top->num, a->top->next->num, a->top->next->next->num);
	set_mid(a);
	if ((a->top->num > a->top->next->num && a->tail->prev->num != a->median)
		|| (a->top->num == min && a->top->next->num == max))
		swap_stack(a, A);
	else if (a->top->num == a->median && a->top->next->num == max)
	{
		reverse_rotate_stack(a, A);
		return ;
	}
	if (a->top->num == a->median)
	{
		reverse_rotate_stack(a, A);
		return ;
	}
	else if (a->tail->prev->num == a->median)
	{
		rotate_stack(a, A);
		return ;
	}
}

void	push_swap_five(t_stack *a, t_stack *b, int range)
{
	int		mid;
	int		i;
	t_node	*cur;

	mid = check_mid_five(a, range);
	cur = a->top;
	i = 0;
	while (i < 5)
	{
		if (cur->num < mid)
			push_stack(a, b, B);
		else
			rotate_stack(a, A);
		cur = a->top;
		i++;
	}
	push_swap_three(a);
	if (b->top->num < b->top->next->num)
		swap_stack(b, B);
	while (b->top != b->tail)
		push_stack(b, a, A);
	return ;
}
