/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:19 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 18:37:35 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_three_ab(t_stack *a)
{
	int	max;
	int	min;

	max = Max(a->top->num, a->top->next->num, a->top->next->next->num);
	min = Min(a->top->num, a->top->next->num, a->top->next->next->num);
	set_mid(a);
	if (a->top->num == min && a->top->next->num == max)
		case_ab_one(a);
	else if (a->top->num == a->median && a->top->next->num == min)
		case_ab_two(a);
	else if (a->top->num == a->median && a->top->next->num == max)
		case_ab_three(a);
	else if (a->top->num == max && a->top->next->num == a->median)
		case_ab_four(a);
	else if (a->top->num == max && a->top->next->num == min)
		case_ab_five(a);
}

int	calc_range_ab(int range, t_stack *a)
{
	if (range == 2)
	{
		if (a->top->num > a->top->next->num)
		{
			swap_stack(a, A);
			return (1);
		}
		else
			return (1);
	}
	else if (range == 3)
	{
		sort_three_ab(a);
		return (1);
	}
	else if (range == 1 || range == 0)
		return (1);
	else
		return (0);
}

static	void	sort_three_ba(t_stack *a, t_stack *b)
{
	int	max;
	int	min;

	max = Max(b->top->num, b->top->next->num, b->top->next->next->num);
	min = Min(b->top->num, b->top->next->num, b->top->next->next->num);
	set_mid(b);
	if (b->top->num == min && b->top->next->num == max)
		case_ba_one(a, b);
	else if (b->top->num == b->median && b->top->next->num == min)
		case_ba_two(a, b);
	else if (b->top->num == b->median && b->top->next->num == max)
		case_ba_three(a, b);
	else if (b->top->num == min && b->top->next->num == b->median)
		case_ba_four(a, b);
	else if (b->top->num == max && b->top->next->num == b->median)
	{
		push_stack(b, a, A);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
	else if (b->top->num == max && b->top->next->num == min)
		case_ba_five(a, b);
}

int	calc_range_ba(int range, t_stack *a, t_stack *b)
{
	if (range == 1)
	{
		push_stack(b, a, A);
		return (1);
	}
	else if (range == 2)
	{
		if (b->top->num < b->top->next->num)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
		return (1);
	}
	else if (range == 3)
	{
		sort_three_ba(a, b);
		return (1);
	}
	else if (range == 0)
		return (1);
	else
		return (0);
}
