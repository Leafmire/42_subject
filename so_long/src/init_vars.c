/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:11:05 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 04:04:15 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_vars(t_vars *vars)
{
	int	i;

	i = 0;
	vars->up = 0;
	vars->down = 0;
	vars->left = 0;
	vars->right = 0;
	vars->mlx = 0;
	vars->win = 0;
	vars->mlx_img.data = 0;
	vars->tile.data = 0;
	vars->wall.data = 0;
	vars->goal.data = 0;
	vars->stair.data = 0;
	vars->player.data = 0;
	vars->gloc = lstnew(0, 0);
	vars->all_collect = 0;
	vars->elem.is_c = 0;
	vars->elem.is_e = 0;
	vars->elem.is_p = 0;
	vars->elem.is_o = 0;
	vars->count = &i;
	return (0);
}
