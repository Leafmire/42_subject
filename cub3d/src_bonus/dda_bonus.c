/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:50:12 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ray_horizontal_util(t_game *game, double x_step, double y_step, \
	double *ayx)
{
	double	new_ay;

	while (ayx[1] >= 0 && ayx[1] <= game->map.total_x * \
		game->screen.map_tile && \
		ayx[0] >= 0 && ayx[0] <= game->map.total_y * game->screen.map_tile)
	{
		new_ay = ayx[0];
		if (game->player.is_ray_up)
			new_ay -= 1;
		if (check_wall(game, ayx[1], new_ay) == 1)
		{
			game->pointh.x = ayx[1];
			game->pointh.y = ayx[0];
			game->pointh.wall_hit = 1;
			break ;
		}
		else
		{
			ayx[1] += x_step;
			ayx[0] += y_step;
		}
	}
}

void	ray_horizontal(t_game *game, double x, double y, double angle)
{
	double	x_step;
	double	y_step;
	double	ayx[2];

	ayx[0] = floor(y / game->screen.map_tile) * game->screen.map_tile;
	if (game->player.is_ray_down)
		ayx[0] += game->screen.map_tile;
	ayx[1] = x + (ayx[0] - y) / tan(angle);
	y_step = game->screen.map_tile;
	if (game->player.is_ray_up)
		y_step *= -1;
	x_step = game->screen.map_tile / tan(angle);
	if (game->player.is_ray_left && x_step > 0)
		x_step *= -1;
	if (game->player.is_ray_right && x_step < 0)
		x_step *= -1;
	game->pointh.wall_hit = 0;
	ray_horizontal_util(game, x_step, y_step, ayx);
}

void	ray_vertical_util(t_game *game, double x_step, double y_step, \
	double *ayx)
{
	double	new_ax;

	while (ayx[1] >= 0 && ayx[1] <= game->map.total_x * \
		game->screen.map_tile && \
		ayx[0] >= 0 && ayx[0] <= game->map.total_y * game->screen.map_tile)
	{
		new_ax = ayx[1];
		if (game->player.is_ray_left)
			new_ax -= 1;
		if (check_wall(game, new_ax, ayx[0]) == 1)
		{
			game->pointv.x = ayx[1];
			game->pointv.y = ayx[0];
			game->pointv.wall_hit = 1;
			break ;
		}
		else
		{
			ayx[1] += x_step;
			ayx[0] += y_step;
		}
	}
}

void	ray_vertical(t_game *game, double x, double y, double angle)
{
	double	x_step;
	double	y_step;
	double	ayx[2];

	ayx[1] = floor(x / game->screen.map_tile) * game->screen.map_tile;
	if (game->player.is_ray_right)
		ayx[1] += game->screen.map_tile;
	ayx[0] = y + (ayx[1] - x) * tan(angle);
	x_step = game->screen.map_tile;
	if (game->player.is_ray_left)
		x_step *= -1;
	y_step = game->screen.map_tile * tan(angle);
	if (game->player.is_ray_up && y_step > 0)
		y_step *= -1;
	if (game->player.is_ray_down && y_step < 0)
		y_step *= -1;
	game->pointv.wall_hit = 0;
	ray_vertical_util(game, x_step, y_step, ayx);
}
