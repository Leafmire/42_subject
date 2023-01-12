/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:17:59 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 07:03:37 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_character(t_vars *vars)
{
	if (vars->elem.is_o == 1)
		error_out("This map has wrong element.", vars);
	if (vars->elem.is_c == 0)
		error_out("This map has no collectable thing.", vars);
	if (vars->elem.is_e == 0)
		error_out("This map has no exit.", vars);
	if (vars->elem.is_p == 0)
		error_out("This map has no start point.", vars);
}

void	map_gnl(char *file, t_vars *vars)
{
	int		fd;
	char	*data;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &data) > 0)
	{
		ft_strlcpy(vars->map.data[i], data, ft_strlen(data) + 1);
		free(data);
		i++;
	}
	free(data);
	close(fd);
}

void	count_map_tile(int fd, t_vars *vars)
{
	int		curr_temp;
	char	c;

	vars->map.cols = 0;
	vars->map.rows = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c != '\n')
		{
			curr_temp++;
			vars->map.cols = curr_temp;
		}
		else
		{
			curr_temp = 0;
			vars->map.rows++;
		}
	}
}

void	map_malloc(int fd, t_vars *vars)
{
	int	i;

	i = 0;
	count_map_tile(fd, vars);
	vars->map.data = (char **)malloc(sizeof(char *) * (vars->map.rows));
	while (i < vars->map.rows)
	{
		vars->map.data[i] = (char *)malloc(sizeof(char) * (vars->map.cols));
		i++;
	}
}

int	map_read(char *file, t_vars *vars)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_out("No such file.", vars);
	if (ft_strncmp(get_ext(file), EXT, ft_strlen(EXT)) != 0)
		error_out("This extension is not supported.", vars);
	map_malloc(fd, vars);
	close(fd);
	map_gnl(file, vars);
	sprite_composition(vars);
	check_square(vars);
	count_element(vars);
	check_character(vars);
	check_wall(vars);
	return (0);
}
