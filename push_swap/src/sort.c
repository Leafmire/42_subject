/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:32 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 18:08:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_count(t_count *count)
{
	count->ra = 0;
	count->pb = 0;
	count->pa = 0;
	count->rb = 0;
}

static	t_count	do_ab(t_stack *a, t_stack *b, int range, t_count *count)
{
	init_count(count);
	while (range-- > 0)
	{
		if (a->top->num > a->median)
		{
			rotate_stack(a, A);
			count->ra++;
		}
		else
		{
			push_stack(a, b, B);
			count->pb++;
			if (b->top->num > a->s_pivot)
			{
				rotate_stack(b, B);
				count->rb++;
			}
		}
	}
	return (*count);
}

void	push_swap_ab(t_stack *a, t_stack *b, int range)
{
	int		i;
	t_count	count;

	if (calc_range_ab(range, a) == 1)
		return ;
	set_pivot(a, range);
	i = 0;
	count = do_ab(a, b, range, &count);
	do_reverse(a, b, &count, i);
	push_swap_ab(a, b, count.ra);
	push_swap_ba(a, b, count.rb);
	push_swap_ba(a, b, count.pb - count.rb);
}

static	t_count	do_ba(t_stack *a, t_stack *b, int range, t_count *count)
{
	init_count(count);
	while (range-- > 0)
	{
		if (b->top->num < b->median)
		{
			rotate_stack(b, B);
			count->rb++;
		}
		else
		{
			push_stack(b, a, A);
			count->pa++;
			if (a->top->num < b->s_pivot)
			{
				rotate_stack(a, A);
				count->ra++;
			}
		}
	}
	return (*count);
}

void	push_swap_ba(t_stack *a, t_stack *b, int range)
{
	int		i;
	t_count	count;

	if (calc_range_ba(range, a, b) == 1)
		return ;
	set_pivot(b, range);
	i = 0;
	count = do_ba(a, b, range, &count);
	push_swap_ab(a, b, count.pa - count.ra);
	do_reverse(a, b, &count, i);
	push_swap_ab(a, b, count.ra);
	push_swap_ba(a, b, count.rb);
}
