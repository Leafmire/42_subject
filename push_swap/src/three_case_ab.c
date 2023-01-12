/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:19 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 17:53:18 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_ab_one(t_stack *a)
{
	rotate_stack(a, A);
	swap_stack(a, A);
	reverse_rotate_stack(a, A);
}

void	case_ab_two(t_stack *a)
{
	swap_stack(a, A);
}

void	case_ab_three(t_stack *a)
{
	rotate_stack(a, A);
	swap_stack(a, A);
	reverse_rotate_stack(a, A);
	swap_stack(a, A);
}

void	case_ab_four(t_stack *a)
{
	swap_stack(a, A);
	rotate_stack(a, A);
	swap_stack(a, A);
	reverse_rotate_stack(a, A);
	swap_stack(a, A);
}

void	case_ab_five(t_stack *a)
{
	swap_stack(a, A);
	rotate_stack(a, A);
	swap_stack(a, A);
	reverse_rotate_stack(a, A);
}
