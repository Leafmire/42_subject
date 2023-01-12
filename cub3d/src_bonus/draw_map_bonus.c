/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:35:20 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	draw_tile(t_game *game, int x, int y, char map_data)
{
	if (map_data == '1')
		mlx_put_pixel(game->image.minimap_img, \
			x, y, 0x000000ff);
	else if (map_data == '0' || map_data == '3')
		mlx_put_pixel(game->image.minimap_img, \
			x, y, 0xFFFFFF77);
	else if (map_data == ' ')
		mlx_put_pixel(game->image.minimap_img, \
			x, y, 0x00000000);
}

void	draw_rectangle(t_game *game, int x, int y, char map_data)
{
	int	i;
	int	j;
	int	tile_size;

	tile_size = game->screen.map_tile;
	x = (x * tile_size) * MINIMAP_SCALE;
	y = (y * tile_size) * MINIMAP_SCALE;
	i = 0;
	while (i < tile_size * MINIMAP_SCALE)
	{
		j = 0;
		while (j < tile_size * MINIMAP_SCALE)
		{
			draw_tile(game, x + j, y + i, map_data);
			j++;
		}
		i++;
	}
}

void	put_minimap(t_game *game)
{
	char	**map_data;
	int		i;
	int		j;

	map_data = game->map.map;
	i = 0;
	while (i < game->map.total_y)
	{
		j = 0;
		while (j < game->map.total_x)
		{
			draw_rectangle(game, j, i, map_data[i][j]);
			j++;
		}
		i++;
	}
}

void	put_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	mlx_put_pixel(game->image.minimap_img, \
		player->x * MINIMAP_SCALE,
		player->y * MINIMAP_SCALE, \
			0x028A0FFF);
}
