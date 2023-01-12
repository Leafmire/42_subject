/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 06:00:08 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 04:08:09 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_image(t_vars *vars, int i, int j)
{
	if (vars->map.data[i][j] == '1')
		draw_sprite(vars, &vars->wall, i * 24, j * 24);
	else if (vars->map.data[i][j] == 'E')
		draw_sprite(vars, &vars->stair, i * 24, j * 24);
	else
		draw_sprite(vars, &vars->tile, i * 24, j * 24);
}

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.rows)
	{
		j = 0;
		while (j < vars->map.cols)
		{
			put_image(vars, i, j);
			j++;
		}
		i++;
	}
	put_goal(vars);
	put_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mlx_img.img_ptr, 0, 0);
}
