/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:09:37 by gson              #+#    #+#             */
/*   Updated: 2022/09/14 14:33:44 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_angle(t_game *game, t_player *p, char direction)
{
	if (direction == 'N')
		p->rotation_angle = PI * 1.5;
	else if (direction == 'E')
		p->rotation_angle = 0;
	else if (direction == 'S')
		p->rotation_angle = PI * 0.5;
	else if (direction == 'W')
		p->rotation_angle = PI;
	else
		error_msg("check cub file (player angle)", PLAYER_INIT_ERR, game);
}

void	find_player(t_game *game, t_player *p, t_map *map_data, char **map)
{
	int		i;
	int		j;
	int		player_cnt;

	player_cnt = 0;
	i = -1;
	while (++i < map_data->total_y)
	{
		j = -1;
		while (++j < map_data->total_x)
		{
			if (map[i][j] >= 65)
			{
				player_cnt++;
				player_angle(game, p, map[i][j]);
				p->x = game->screen.map_tile * j + \
					(game->screen.map_tile / 2.0);
				p->y = game->screen.map_tile * i + \
					(game->screen.map_tile / 2.0);
				map[i][j] = '0';
			}
		}
	}
	if (player_cnt != 1)
		error_msg("check cub file (number of player)", PLAYER_INIT_ERR, game);
}

int	init_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	player->x = 0;
	player->y = 0;
	player->size = PLAYER_SIZE;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = 0;
	player->move_speed = 5.0;
	player->rotation_speed = 2 * (PI / 180);
	find_player(game, player, &game->map, game->map.map);
	return (0);
}
