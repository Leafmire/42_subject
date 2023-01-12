/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:20:58 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	init_screen(t_game *game)
{
	t_screen	*screen;

	screen = &game->screen;
	screen->map_tile = SCREEN_W / game->map.total_x;
	screen->screen_w = SCREEN_W;
	screen->screen_h = game->map.total_y * screen->map_tile;
	game->mlx = mlx_init(SCREEN_W, SCREEN_H, "gson_cub3d", true);
	if (!game->mlx)
		error_msg("mlx init error", MLX_INIT_ERROR, game);
	return (0);
}

int	init_txt(t_game *game)
{
	t_texture	*texture;

	texture = &game->texture;
	texture->n_wall_txt = mlx_load_png(game->texture.n_wall_path);
	if (!texture->n_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, game);
	texture->s_wall_txt = mlx_load_png(game->texture.s_wall_path);
	if (!texture->s_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, game);
	texture->w_wall_txt = mlx_load_png(game->texture.w_wall_path);
	if (!texture->w_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, game);
	texture->e_wall_txt = mlx_load_png(game->texture.e_wall_path);
	if (!texture->e_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, game);
	return (0);
}

int	init_img(t_game *game)
{
	t_image	*image;

	image = &game->image;
	image->cub_img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	if (!image->cub_img)
		error_msg("mlx image create error", MLX_INIT_ERROR, game);
	return (0);
}

void	check_file(t_game *game, char *map_path)
{
	if (!ft_strnstr(map_path, ".cub", ft_strlen(map_path)))
		error_msg("Invalid file extension", FILE_NAME_ERROR, game);
}

void	init_data(t_game *game, char *map_path)
{
	game->map.map_path = map_path;
	check_file(game, map_path);
	init_cub_file_option(game);
	init_map(game);
	init_screen(game);
	init_minimap(game);
	init_img(game);
	init_txt(game);
	init_player(game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
}
