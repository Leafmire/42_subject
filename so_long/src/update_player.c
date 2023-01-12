/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:30:05 by gson              #+#    #+#             */
/*   Updated: 2021/11/21 22:49:12 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	make_collision(t_vars *vars, int y, int x)
{
	int	i;
	int	j;

	i = y / 24;
	j = x / 24;
	if (vars->map.data[i][j] == '1')
	{
		vars->ploc.y = vars->ploc.y;
		vars->ploc.x = vars->ploc.x;
	}
	else
	{	
		vars->ploc.y = y;
		vars->ploc.x = x;
		*vars->count = *vars->count + 1;
		ft_putnbr_fd(*vars->count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	update_player(t_vars *vars)
{
	if (vars->up == 1)
		make_collision(vars, vars->ploc.y - 24, vars->ploc.x);
	else if (vars->down == 1)
		make_collision(vars, vars->ploc.y + 24, vars->ploc.x);
	else if (vars->left == 1)
		make_collision(vars, vars->ploc.y, vars->ploc.x - 24);
	else if (vars->right == 1)
		make_collision(vars, vars->ploc.y, vars->ploc.x + 24);
}
