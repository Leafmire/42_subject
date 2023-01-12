/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:23:55 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	rotate_player(t_player *player)
{
	player->rotation_angle += player->turn_direction * player->rotation_speed;
}

int	check_wall_4d_h(t_game *game, double move_step, double *x, double *y)
{
	if (check_wall(game, \
		x[0] + cos(game->player.rotation_angle + (PI / 2)) * move_step, \
		y[0] + sin(game->player.rotation_angle + (PI / 2)) * move_step) != 1 && \
		check_wall(game, \
		x[1] + cos(game->player.rotation_angle + (PI / 2)) * move_step, \
		y[0] + sin(game->player.rotation_angle + (PI / 2)) * move_step) != 1 && \
		check_wall(game, \
		x[0] + cos(game->player.rotation_angle + (PI / 2)) * move_step, \
		y[1] + sin(game->player.rotation_angle + (PI / 2)) * move_step) != 1 && \
		check_wall(game, \
		x[1] + cos(game->player.rotation_angle + (PI / 2)) * move_step, \
		y[1] + sin(game->player.rotation_angle + (PI / 2)) * move_step) != 1)
		return (0);
	return (1);
}

int	check_wall_4d_v(t_game *game, double move_step, double *x, double *y)
{
	if (check_wall(game, \
		x[0] + cos(game->player.rotation_angle) * move_step, \
		y[0] + sin(game->player.rotation_angle) * move_step) != 1 && \
		check_wall(game, \
		x[1] + cos(game->player.rotation_angle) * move_step, \
		y[0] + sin(game->player.rotation_angle) * move_step) != 1 && \
		check_wall(game, \
		x[0] + cos(game->player.rotation_angle) * move_step, \
		y[1] + sin(game->player.rotation_angle) * move_step) != 1 && \
		check_wall(game, \
		x[1] + cos(game->player.rotation_angle) * move_step, \
		y[1] + sin(game->player.rotation_angle) * move_step) != 1)
		return (0);
	return (1);
}

void	move_player(t_game *game, t_player *player, char ch)
{
	double	move_step;
	double	x[2];
	double	y[2];

	move_step = player->walk_direction * player->move_speed;
	x[0] = player->x - (PLAYER_SIZE / 2.0);
	x[1] = player->x + (PLAYER_SIZE / 2.0);
	y[0] = player->y - (PLAYER_SIZE / 2.0);
	y[1] = player->y + (PLAYER_SIZE / 2.0);
	if ((check_wall_4d_v(game, move_step, x, y) != 1) && (ch == 'v'))
	{
		player->x = player->x + cos(player->rotation_angle) * move_step;
		player->y = player->y + sin(player->rotation_angle) * move_step;
	}
	if ((check_wall_4d_h(game, move_step, x, y) != 1) && (ch == 'h'))
	{
		player->x = player->x + cos(player->rotation_angle + (PI / 2)) \
			* move_step;
		player->y = player->y + sin(player->rotation_angle + (PI / 2)) \
			* move_step;
	}
}
