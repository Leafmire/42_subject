/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:22 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 05:30:58 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_image(t_vars *vars, t_img *img, char *path)
{
	int	width;
	int	height;

	img->img_ptr = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	if (img == 0)
		error_out("Can not found xpm file.", vars);
	img->data = mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_line, &img->endian);
}

void	set_image(t_vars *vars)
{
	load_image(vars, &vars->tile, "./img/tile.xpm");
	load_image(vars, &vars->wall, "./img/wall.xpm");
	load_image(vars, &vars->goal, "./img/goal.xpm");
	load_image(vars, &vars->stair, "./img/stair.xpm");
	load_image(vars, &vars->player, "./img/player_down.xpm");
}
