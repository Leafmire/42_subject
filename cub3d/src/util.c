/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 06:12:30 by gson              #+#    #+#             */
/*   Updated: 2022/09/14 16:11:14 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	gnl_flush(int fd)
{
	char	*read_line;

	read_line = get_next_line(fd);
	while (read_line)
	{
		free(read_line);
		read_line = get_next_line(fd);
	}
}

double	normalize_angle(double angle)
{
	double	n_angle;

	n_angle = remainder(angle, TWO_PI);
	if (n_angle < 0)
		n_angle = TWO_PI + n_angle;
	return (n_angle);
}

int	calculate_distance(t_player *player, t_pointh *pointh, t_pointv *pointv)
{
	double	horizon_d;
	double	vertical_d;

	if (pointh->wall_hit == 1)
	{
		horizon_d = sqrt((player->x - pointh->x) * (player->x - pointh->x) + \
			(player->y - pointh->y) * (player->y - pointh->y));
	}
	else
	{
		horizon_d = DBL_MAX;
	}
	pointh->distance = horizon_d;
	if (pointv->wall_hit == 1)
	{
		vertical_d = sqrt((player->x - pointv->x) * (player->x - pointv->x) + \
			(player->y - pointv->y) * (player->y - pointv->y));
	}
	else
	{
		vertical_d = DBL_MAX;
	}
	pointv->distance = vertical_d;
	return (horizon_d > vertical_d);
}

void	set_ray(t_game *game, t_pointh pointh, t_pointv pointv, char hit)
{
	if (hit == 'h')
	{
		game->ray.x = pointh.x;
		game->ray.y = pointh.y;
		game->ray.distance = pointh.distance;
		game->ray.hit_hv = 0;
	}
	else
	{
		game->ray.x = pointv.x;
		game->ray.y = pointv.y;
		game->ray.distance = pointv.distance;
		game->ray.hit_hv = 1;
	}
}

void	put_cub_pixel(t_game *game)
{
	int			y;
	int			x;
	uint32_t	f_color;
	uint32_t	c_color;

	f_color = game->texture.floor_color;
	c_color = game->texture.ceiling_color;
	y = 0;
	while (y < 540)
	{
		x = 0;
		while (x < 1960)
			mlx_put_pixel(game->image.cub_img, x++, y, c_color);
		y++;
	}
	while (y < 1080)
	{
		x = 0;
		while (x < 1960)
			mlx_put_pixel(game->image.cub_img, x++, y, f_color);
		y++;
	}
}
