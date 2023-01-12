/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 02:22:29 by gson              #+#    #+#             */
/*   Updated: 2022/09/14 16:11:22 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	read_line_free(char *read_line)
{
	if (read_line != NULL)
	{
		free(read_line);
		read_line = NULL;
	}
}

int	free_char(char **game)
{
	int	idx;

	idx = 0;
	if (!game)
		return (0);
	while (game[idx])
	{
		free(game[idx]);
		idx++;
	}
	free(game);
	return (1);
}

void	free_option(t_game *game)
{
	t_texture	*txt;

	txt = &game->texture;
	if (txt->n_wall_path)
		free(txt->n_wall_path);
	if (txt->s_wall_path)
		free(txt->s_wall_path);
	if (txt->e_wall_path)
		free(txt->e_wall_path);
	if (txt->w_wall_path)
		free(txt->w_wall_path);
	free_char(txt->floor_txt);
	free_char(txt->ceiling_txt);
}

void	free_map(t_game *game)
{
	char	**map;

	map = game->map.map;
	free_char(map);
}

void	free_all(t_game *game)
{
	free_option(game);
	free_map(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(0);
}
