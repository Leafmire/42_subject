/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:20:07 by gson              #+#    #+#             */
/*   Updated: 2022/09/14 21:00:20 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	game_hook(void *param)
{
	t_game	*game;

	game = param;
	game->player.walk_direction = 0;
	game->player.turn_direction = 0;
	mlx_set_mouse_pos(game->mlx, SCREEN_W / 2, SCREEN_H / 2);
	put_cub_pixel(game);
	put_minimap(game);
	put_player(game);
	init_rays(game, &game->player);
	player_hook_fb(game);
	player_hook_lr(game);
	player_hook_arrow(game);
	player_hook_mouse(game);
}

static void	ft_close(void *param)
{
	t_game	*game;

	game = param;
	free_all(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_msg("arg error", ARG_ERROR, &game);
	init_data(&game, argv[1]);
	mlx_image_to_window(game.mlx, game.image.cub_img, 0, 0);
	mlx_image_to_window(game.mlx, game.image.minimap_img, 0, 0);
	mlx_loop_hook(game.mlx, &game_hook, &game);
	mlx_close_hook(game.mlx, &ft_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
