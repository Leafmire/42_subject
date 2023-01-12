/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:34:17 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 15:56:42 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_point(t_pointh *pointh, t_pointv *pointv)
{
	pointh->x = 0;
	pointh->y = 0;
	pointh->distance = 0;
	pointh->wall_hit = 0;
	pointv->x = 0;
	pointv->y = 0;
	pointv->distance = 0;
	pointv->wall_hit = 0;
}

int	ray_interseption(t_game *game, double x, double y, double angle)
{
	double	n_angle;

	n_angle = normalize_angle(angle);
	game->player.is_ray_down = (n_angle > 0 && n_angle < PI);
	game->player.is_ray_up = !(game->player.is_ray_down);
	game->player.is_ray_right = (n_angle < PI * 0.5 || n_angle > PI * 1.5);
	game->player.is_ray_left = !(game->player.is_ray_right);
	init_point(&game->pointh, &game->pointv);
	ray_horizontal(game, x, y, n_angle);
	ray_vertical(game, x, y, n_angle);
	if (calculate_distance(&game->player, &game->pointh, &game->pointv) == 1)
	{
		set_ray(game, game->pointh, game->pointv, 'v');
		return (1);
	}
	else
	{
		set_ray(game, game->pointh, game->pointv, 'h');
		return (0);
	}
}

void	draw_ray_perform(t_game *game, double length, \
	double delta_x, double delta_y)
{
	double	pixel_x;
	double	pixel_y;
	int		i;

	pixel_x = game->player.x * MINIMAP_SCALE;
	pixel_y = game->player.y * MINIMAP_SCALE;
	i = 0;
	while (i < floor(length))
	{
		mlx_put_pixel(game->image.minimap_img, pixel_x, pixel_y, 0x028A0FFF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		i++;
	}
}

void	draw_ray(t_game *game, t_player *player, double angle)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	double	length;

	pixel_x = player->x;
	pixel_y = player->y;
	if (ray_interseption(game, player->x, player->y, angle) == 0)
	{
		delta_x = (game->pointh.x - pixel_x) * MINIMAP_SCALE;
		delta_y = (game->pointh.y - pixel_y) * MINIMAP_SCALE;
	}
	else
	{
		delta_x = (game->pointv.x - pixel_x) * MINIMAP_SCALE;
		delta_y = (game->pointv.y - pixel_y) * MINIMAP_SCALE;
	}
	length = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= length;
	delta_y /= length;
	draw_ray_perform(game, length, delta_x, delta_y);
}

void	init_rays(t_game *game, t_player *player)
{
	double	angle;
	double	angle_rad;
	int		i;

	angle_rad = FOV * (PI / 180);
	angle = player->rotation_angle - (angle_rad / 2.0);
	i = 0;
	while (i < SCREEN_W)
	{
		draw_ray(game, player, angle);
		render_wall(game, i, angle);
		angle += (angle_rad / (SCREEN_W)) * 2;
		i += 2;
	}
}
