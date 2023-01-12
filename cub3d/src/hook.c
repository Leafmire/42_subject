/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:47:44 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 14:54:05 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_hook_mouse(t_game *game)
{
	int32_t	x_out;
	int32_t	y_out;

	mlx_get_mouse_pos(game->mlx, &x_out, &y_out);
	if (x_out < SCREEN_W / 2)
	{
		game->player.turn_direction = -1;
		rotate_player(&game->player);
	}
	else if (x_out > SCREEN_W / 2)
	{
		game->player.turn_direction = 1;
		rotate_player(&game->player);
	}
}

void	player_hook_arrow(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player.turn_direction = -1;
		rotate_player(&game->player);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player.turn_direction = 1;
		rotate_player(&game->player);
	}
}

void	player_hook_lr(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && \
		mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.walk_direction = 0;
	}	
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.walk_direction = -1;
		move_player(game, &game->player, 'h');
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.walk_direction = 1;
		move_player(game, &game->player, 'h');
	}
}

void	player_hook_fb(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		free_all(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && \
		mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.walk_direction = 0;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player.walk_direction = 1;
		move_player(game, &game->player, 'v');
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.walk_direction = -1;
		move_player(game, &game->player, 'v');
	}
}
