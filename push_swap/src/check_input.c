/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:29 by gson              #+#    #+#             */
/*   Updated: 2022/02/09 20:01:49 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur->next != a->tail)
	{
		if (cur->num > cur->next->num)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	iscontain_char(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	is_duplicated(t_stack *a)
{
	t_node	*cur;
	t_node	*move;

	cur = a->top;
	while (cur != a->tail)
	{
		move = cur->next;
		while (move != a->tail)
		{
			if (cur->num == move->num)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			move = move->next;
		}
		cur = cur->next;
	}
}

static	void	split_space(char *str, t_stack *stack_a)
{
	char	**split;
	int		i;

	split = ft_split(str, ' ');
	i = 0;
	while (split[i] != NULL)
		i++;
	while (i > 0)
	{
		push(stack_a, ft_atoi(split[i - 1]));
		free(split[i - 1]);
		i--;
	}
	free(split);
}

void	check_input(int argc, char **argv, t_stack *stack_a)
{
	if (argc <= 2)
	{
		if (ft_strchr(argv[1], ' ') != NULL)
			split_space(argv[1], stack_a);
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	else
	{
		while (argc > 1)
		{
			if (ft_strchr(argv[argc - 1], ' ') != NULL)
				split_space(argv[argc - 1], stack_a);
			else
				push(stack_a, ft_atoi(argv[argc - 1]));
			argc--;
		}
	}
	is_duplicated(stack_a);
	if (check_sorted(stack_a) == 0)
		exit(1);
}
