/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_edit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:47 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 16:08:49 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack, int type)
{
	int	temp_num;

	temp_num = stack->top->num;
	stack->top->num = stack->top->next->num;
	stack->top->next->num = temp_num;
	if (type == A)
		ft_putstr_fd("sa\n", 1);
	else if (type == B)
		ft_putstr_fd("sb\n", 1);
}

void	push_stack(t_stack *out, t_stack *put, int type)
{
	int	num;

	num = out->top->num;
	push(put, num);
	pop(out);
	if (type == A)
		ft_putstr_fd("pa\n", 1);
	else if (type == B)
		ft_putstr_fd("pb\n", 1);
}

void	rotate_stack(t_stack *stack, int type)
{
	t_node	*node;

	if (ft_lstsize(stack) <= 1)
		return ;
	node = stack->top;
	stack->head->next = node->next;
	node->next->prev = stack->head;
	node->next = stack->tail;
	node->prev = stack->tail->prev;
	stack->tail->prev = node;
	node->prev->next = node;
	stack->top = stack->head->next;
	if (type == A)
		ft_putstr_fd("ra\n", 1);
	else if (type == B)
		ft_putstr_fd("rb\n", 1);
	else
		return ;
}

void	reverse_rotate_stack(t_stack *stack, int type)
{
	t_node	*node;

	if (ft_lstsize(stack) <= 1)
		return ;
	node = stack->tail->prev;
	stack->tail->prev = node->prev;
	node->prev->next = stack->tail;
	node->prev = stack->head;
	stack->head->next = node;
	node->next = stack->top;
	stack->top->prev = node;
	stack->top = node;
	if (type == A)
		ft_putstr_fd("rra\n", 1);
	else if (type == B)
		ft_putstr_fd("rrb\n", 1);
	else
		return ;
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a, ALL);
	reverse_rotate_stack(b, ALL);
	ft_putstr_fd("rrr\n", 1);
}
