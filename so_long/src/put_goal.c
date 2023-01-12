/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_goal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 07:49:04 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 03:55:47 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_goal(t_vars *vars)
{
	t_goal	*node;

	node = vars->gloc;
	while (node != 0)
	{
		if (node->is_collect == 0)
		{
			draw_sprite(vars, &vars->goal, node->y, node->x);
		}
		node = node->next;
	}
}
