/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:22:02 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 14:54:21 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t	get_color_txt(uint32_t color)
{
	uint32_t		bytes[4];
	uint32_t		ret;

	bytes[0] = ((color >> 24) & 0xff);
	bytes[1] = ((color >> 16) & 0xff);
	bytes[2] = ((color >> 8) & 0xff);
	bytes[3] = ((color >> 0) & 0xff);
	ret = (bytes[0] << 0) | \
		(bytes[1] << 8) | \
		(bytes[2] << 16) | \
		(bytes[3] << 24);
	return (ret);
}

int	find_texture_x_pos(t_game *game, mlx_texture_t *wall_txt)
{
	int	texture_x;

	if (game->ray.hit_hv == 1)
		texture_x = ((int)game->ray.y % game->screen.map_tile) * \
			(wall_txt->width / game->screen.map_tile);
	else
		texture_x = ((int)game->ray.x % game->screen.map_tile) * \
			(wall_txt->width / game->screen.map_tile);
	return (texture_x);
}

void	draw_wall(t_game *game, int wall_h, int ray_num, \
	mlx_texture_t *wall_txt)
{
	int			top;
	int			bottom;
	int			texture_y;
	int			d_from_top;
	uint32_t	color;

	top = (SCREEN_H / 2) - (wall_h / 2);
	if (top < 0)
		top = 0;
	bottom = (SCREEN_H / 2) + (wall_h / 2);
	if (bottom > SCREEN_H)
		bottom = SCREEN_H;
	while (top < bottom)
	{
		d_from_top = top + (wall_h / 2) - (SCREEN_H / 2);
		texture_y = (d_from_top * wall_txt->height) / wall_h;
		color = *((uint32_t *)wall_txt->pixels + \
			(wall_txt->width * texture_y + \
			find_texture_x_pos(game, wall_txt)));
		color = get_color_txt(color);
		mlx_put_pixel(game->image.cub_img, ray_num, top, color);
		mlx_put_pixel(game->image.cub_img, ray_num + 1, top, color);
		top++;
	}
}

mlx_texture_t	*set_reflect_wall(t_game *game)
{
	mlx_texture_t	*wall_txt;

	if (game->ray.hit_hv == 1)
	{
		if (game->player.is_ray_right)
			wall_txt = game->texture.w_wall_txt;
		else
			wall_txt = game->texture.e_wall_txt;
	}
	else
	{
		if (game->player.is_ray_down)
			wall_txt = game->texture.n_wall_txt;
		else
			wall_txt = game->texture.s_wall_txt;
	}
	return (wall_txt);
}

void	render_wall(t_game *game, int ray_num, double angle)
{
	double	ray_distance;
	double	projected_hight;
	double	plane_distance;
	double	correct_distance;
	int		wall_h;

	ray_distance = game->ray.distance;
	correct_distance = ray_distance * cos(angle - game->player.rotation_angle);
	plane_distance = (SCREEN_W / 2.0) / tan(FOV * (PI / 180) / 2.0);
	projected_hight = (game->screen.map_tile / correct_distance) * \
		plane_distance;
	wall_h = (int)projected_hight;
	draw_wall(game, wall_h, ray_num, set_reflect_wall(game));
}
