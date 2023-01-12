/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:45:11 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	to_map(t_game *game, char *map_path, int option_line_count)
{
	int		fd;
	char	*read_line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_msg("file open error", MAP_INIT_ERROR, game);
	close(fd);
	gnl_flush(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_msg("file open error", MAP_INIT_ERROR, game);
	while (option_line_count--)
	{
		read_line = get_next_line(fd);
		read_line_free(read_line);
	}
	return (fd);
}

void	find_map_section(t_game *game, char *map_path, int *option_line_count)
{
	int		fd;
	char	*read_line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_msg("file open error", MAP_INIT_ERROR, game);
	close(fd);
	gnl_flush(fd);
	fd = open(map_path, O_RDONLY);
	while (1)
	{
		read_line = get_next_line(fd);
		if (is_map_option(read_line))
		{
			read_line_free(read_line);
			break ;
		}
		++*option_line_count;
		free(read_line);
	}
}

int	check_map(t_game *game, t_map *map_data, int fd)
{
	char	*read_line;
	int		total_x;

	map_data->total_y = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line || map_line_check(read_line))
		{
			read_line_free(read_line);
			break ;
		}
		map_data->total_y++;
		total_x = ft_strlen(read_line) - 1;
		if (total_x >= map_data->total_x)
			map_data->total_x = total_x;
		free(read_line);
	}
	close(fd);
	if (map_line_check(read_line))
		error_msg("invalid map", MAP_INIT_ERROR, game);
	map_data->map = (char **)malloc(sizeof(char *) * (map_data->total_y + 1));
	map_data->map[map_data->total_y] = NULL;
	return (0);
}

int	load_map(t_map *map_data, int fd)
{
	char	*read_line;
	char	*map_line;
	int		idx;

	idx = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		map_line = malloc(map_data->total_x + 1);
		ft_memset(map_line, ' ', map_data->total_x);
		ft_memcpy(map_line, read_line, ft_strlen(read_line) - 1);
		map_line[map_data->total_x] = 0;
		map_data->map[idx] = map_line;
		idx++;
		free(read_line);
	}
	close(fd);
	return (0);
}

int	init_map(t_game *game)
{
	t_map	*map_data;
	char	*map_path;
	int		fd;
	int		option_line_count;

	map_data = &game->map;
	map_path = map_data->map_path;
	map_data->map = NULL;
	option_line_count = 0;
	find_map_section(game, map_path, &option_line_count);
	map_data->total_x = 0;
	check_map(game, map_data, to_map(game, map_path, option_line_count));
	fd = to_map(game, map_path, option_line_count);
	load_map(map_data, fd);
	if (map_data->total_y == 0 || map_data->total_x == 0)
		error_msg("invalid map", MAP_INIT_ERROR, game);
	if (check_map_valid(map_data->map, map_data->total_y, map_data->total_x))
		error_msg("map is not closed", MAP_INIT_ERROR, game);
	return (0);
}
