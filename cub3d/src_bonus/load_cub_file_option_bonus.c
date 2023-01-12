/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cub_file_option_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:13:21 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	color_len(char **cnf)
{
	int	color_num;

	color_num = 0;
	while (cnf[color_num])
		color_num++;
	return (color_num);
}

int	char_to_color(char **cnf, t_game *game)
{
	int	color;
	int	bytes;
	int	cnt;
	int	idx;

	cnt = 3;
	idx = 0;
	color = 0;
	if (color_len(cnf) != 3)
		error_msg("floor, ceiling value is corrupted", OPTION_INIT_ERROR, game);
	while (cnt--)
	{
		bytes = ft_atoi(cnf[idx]);
		if (bytes < 0 || bytes > 255)
			error_msg("floor, ceiling value is corrupted", \
					OPTION_INIT_ERROR, game);
		color |= bytes << (cnt + 1) * 8;
		idx++;
	}
	color |= 0xFF;
	return (color);
}

int	load_wall_text(char **path, char *read_line)
{
	if (*path != NULL || *read_line == '\0')
		return (1);
	*path = ft_substr(read_line, 0, ft_strlen(read_line) - 1);
	return (0);
}

int	load_fc_text(char ***color_text, char *read_line)
{
	if (*read_line == '\0' || !ft_isdigit(*read_line))
		return (1);
	*color_text = ft_split(read_line, ',');
	return (0);
}

int	load_option(t_game *game, char *type, char *read_line)
{
	while (*read_line == ' ')
		read_line++;
	if (*read_line != '\0')
	{
		read_line += ft_strlen(type);
		while (*read_line == ' ')
			read_line++;
		if (!ft_strncmp(type, "NO ", 3))
			return (load_wall_text(&game->texture.n_wall_path, read_line));
		else if (!ft_strncmp(type, "SO ", 3))
			return (load_wall_text(&game->texture.s_wall_path, read_line));
		else if (!ft_strncmp(type, "WE ", 3))
			return (load_wall_text(&game->texture.w_wall_path, read_line));
		else if (!ft_strncmp(type, "EA ", 3))
			return (load_wall_text(&game->texture.e_wall_path, read_line));
		else if (!ft_strncmp(type, "F ", 2))
			return (load_fc_text(&game->texture.floor_txt, read_line));
		else if (!ft_strncmp(type, "C ", 2))
			return (load_fc_text(&game->texture.ceiling_txt, read_line));
	}
	return (1);
}
