/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:30:05 by gson              #+#    #+#             */
/*   Updated: 2021/11/20 07:36:49 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_collect_all(t_vars *vars)
{
	t_goal	*node;

	node = vars->gloc;
	while (node != 0)
	{
		if (node->is_collect == 0)
		{
			vars->all_collect = 0;
			break ;
		}
		vars->all_collect = 1;
		if (node->next == 0)
			break ;
		node = node->next;
	}
}

void	update_collect(t_vars *vars)
{
	int		i;
	int		j;
	t_goal	*node;

	node = vars->gloc;
	i = vars->ploc.y / 24;
	j = vars->ploc.x / 24;
	if (vars->map.data[i][j] == 'C')
	{
		while (node != 0)
		{
			if (node->y == vars->ploc.y && node->x == vars->ploc.x)
			{
				node->is_collect = 1;
				break ;
			}
			node = node->next;
		}
	}
}
