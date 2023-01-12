/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 09:49:11 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 05:29:45 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

unsigned int	mlx_get_pixel(t_img *img, int y, int x)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int y, int x, unsigned int color)
{
	char	*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
