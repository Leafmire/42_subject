/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:05:26 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 05:30:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_map(t_vars *vars)
{
	vars->width = (vars->map.cols) * 24;
	vars->height = (vars->map.rows) * 24;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width,
			vars->height, "so_long");
	vars->mlx_img.img_ptr = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->mlx_img.data = mlx_get_data_addr(
			vars->mlx_img.img_ptr,
			&vars->mlx_img.bpp,
			&vars->mlx_img.size_line,
			&vars->mlx_img.endian);
	return (0);
}
