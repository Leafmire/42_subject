/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:41:26 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:13:40 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_minimap(t_game *game)
{
	t_screen	*screen;

	screen = &game->screen;
	screen->minimap_tile = floor(screen->map_tile * MINIMAP_SCALE);
	game->image.minimap_img = mlx_new_image(game->mlx, \
		(game->map.total_x * screen->map_tile) * MINIMAP_SCALE, \
		(game->map.total_y * screen->map_tile) * MINIMAP_SCALE);
}
