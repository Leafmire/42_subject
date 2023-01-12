/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_file_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:28:22 by soum              #+#    #+#             */
/*   Updated: 2022/09/15 14:54:08 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_texture(t_game *game)
{
	t_texture	*texture;

	texture = &game->texture;
	texture->ceiling_txt = NULL;
	texture->floor_txt = NULL;
	texture->n_wall_path = NULL;
	texture->s_wall_path = NULL;
	texture->e_wall_path = NULL;
	texture->w_wall_path = NULL;
}

int	check_read_line(char *read_line, t_game *game)
{
	if (read_line[0] == '\n')
		return (0);
	if (ft_strnstr(read_line, "NO ", ft_strlen(read_line)))
		return (load_option(game, "NO ", read_line));
	else if (ft_strnstr(read_line, "SO ", ft_strlen(read_line)))
		return (load_option(game, "SO ", read_line));
	else if (ft_strnstr(read_line, "WE ", ft_strlen(read_line)))
		return (load_option(game, "WE ", read_line));
	else if (ft_strnstr(read_line, "EA ", ft_strlen(read_line)))
		return (load_option(game, "EA ", read_line));
	else if (ft_strnstr(read_line, "F ", ft_strlen(read_line)))
		return (2 * load_option(game, "F ", read_line));
	else if (ft_strnstr(read_line, "C ", ft_strlen(read_line)))
		return (2 * load_option(game, "C ", read_line));
	return (4);
}

void	check_file_option(t_game *game)
{
	int		fd;
	char	*read_line;
	int		check;

	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		error_msg("map file open error", FILE_OPEN_ERROR, game);
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line || is_map_option(read_line))
		{
			read_line_free(read_line);
			break ;
		}
		check = check_read_line(read_line, game);
		if (check == 1)
			error_msg("wall texture duplicated", OPTION_INIT_ERROR, game);
		else if (check == 2)
			error_msg("floor / ceiling game is unvailable or duplicated", \
					OPTION_INIT_ERROR, game);
		free(read_line);
	}
	close(fd);
}

void	is_option_empty(t_game *game)
{
	t_texture	text;

	text = game->texture;
	if (!text.n_wall_path)
		error_msg("north wall path is empty", OPTION_INIT_ERROR, game);
	if (!text.s_wall_path)
		error_msg("south wall path is empty", OPTION_INIT_ERROR, game);
	if (!text.w_wall_path)
		error_msg("west wall path is empty", OPTION_INIT_ERROR, game);
	if (!text.e_wall_path)
		error_msg("east wall path is empty", OPTION_INIT_ERROR, game);
	if (!text.floor_txt)
		error_msg("floor color is empty", OPTION_INIT_ERROR, game);
	if (!text.ceiling_txt)
		error_msg("ceiling color is empty", OPTION_INIT_ERROR, game);
}

void	init_cub_file_option(t_game *game)
{
	t_texture	*texture;

	texture = &game->texture;
	init_texture(game);
	check_file_option(game);
	is_option_empty(game);
	texture->ceiling_color = char_to_color(texture->ceiling_txt, game);
	texture->floor_color = char_to_color(texture->floor_txt, game);
}
