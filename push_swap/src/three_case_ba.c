/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case_ba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:19 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 17:44:06 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_ba_one(t_stack *a, t_stack *b)
{
	rotate_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
	reverse_rotate_stack(b, B);
	push_stack(b, a, A);
}

void	case_ba_two(t_stack *a, t_stack *b)
{
	rotate_stack(b, B);
	swap_stack(b, B);
	push_stack(b, a, A);
	reverse_rotate_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
}

void	case_ba_three(t_stack *a, t_stack *b)
{
	swap_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
	push_stack(b, a, A);
}

void	case_ba_four(t_stack *a, t_stack *b)
{
	rotate_stack(b, B);
	swap_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
	reverse_rotate_stack(b, B);
	push_stack(b, a, A);
}

void	case_ba_five(t_stack *a, t_stack *b)
{
	push_stack(b, a, A);
	swap_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
}
