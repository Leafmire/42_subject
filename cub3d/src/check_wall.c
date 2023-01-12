/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:35:55 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 15:46:47 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_wall(t_game *game, double x, double y)
{
	int	grid_x;
	int	grid_y;
	int	tile_size;

	tile_size = game->screen.map_tile;
	if (x < 0 || x >= game->map.total_x * tile_size || \
		y < 0 || y >= game->map.total_y * tile_size)
		return (1);
	grid_x = floor(x / game->screen.map_tile);
	grid_y = floor(y / game->screen.map_tile);
	return (game->map.map[grid_y][grid_x] == '1');
}
