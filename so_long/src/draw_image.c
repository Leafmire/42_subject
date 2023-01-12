/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 05:58:13 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 05:34:46 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_sprite(t_vars *vars, t_img *img, int y, int x)
{
	unsigned int	color;
	int				i;
	int				j;

	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(&vars->mlx_img, y + i, x + j, color);
			j++;
		}
		i++;
	}
}
