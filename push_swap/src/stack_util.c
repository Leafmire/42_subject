/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:41 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 18:41:13 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int num)
{
	t_node	*newNode;

	newNode = (t_node *)malloc(sizeof(t_node));
	newNode->num = num;
	stack->top->prev = newNode;
	stack->head->next = newNode;
	newNode->prev = stack->head;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->length++;
}

int	pop(t_stack *stack)
{
	t_node	*deleteNode;
	int		num;

	if (stack->top != stack->tail)
	{
		deleteNode = stack->top;
		stack->top = deleteNode->next;
		stack->head->next = stack->top;
		stack->top->prev = stack->head;
		num = deleteNode->num;
		stack->length--;
		free(deleteNode);
		return (num);
	}
	else
		return (0);
}

void	set_mid(t_stack *a)
{
	t_node	*cur;
	int		max;
	int		min;

	if (a->top == a->tail)
		return ;
	cur = a->top;
	if (ft_lstsize(a) >= 3)
	{
		max = Max(cur->num, cur->next->num,
				cur->next->next->num);
		min = Min(cur->num, cur->next->num,
				cur->next->next->num);
		a->median = (cur->num + cur->next->num
				+ cur->next->next->num) - max - min;
		a->s_pivot = min;
	}
	else
	{
		a->median = cur->num;
		a->s_pivot = cur->next->num;
	}
}

void	set_pivot(t_stack *a, int range)
{
	int		*list;
	int		i;
	t_node	*cur;

	list = (int *)malloc(sizeof(int) * range);
	cur = a->top;
	i = 0;
	while (i < range)
	{
		list[i] = cur->num;
		cur = cur->next;
		i++;
	}
	list = bubble_sort(list, range);
	a->median = list[range / 3 * 2];
	a->s_pivot = list[range / 3];
	free(list);
}
