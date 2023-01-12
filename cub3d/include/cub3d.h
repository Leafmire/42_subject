/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:21:10 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:17:35 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <fcntl.h>

# define ARG_ERROR 1
# define FILE_OPEN_ERROR 2
# define FILE_NAME_ERROR 2
# define OPTION_INIT_ERROR 3
# define MAP_INIT_ERROR 4
# define MLX_INIT_ERROR 5
# define PLAYER_INIT_ERR 6

# define PI 3.14159265
# define TWO_PI 6.28318530

# define PLAYER_SIZE 5

# define MINIMAP_SCALE 0.2

# define SCREEN_W 1960
# define SCREEN_H 1080
# define DBL_MAX 1E+37
# define FOV 60

typedef struct s_pointh
{
	double	x;
	double	y;
	double	distance;
	int		wall_hit;
}t_pointh;

typedef struct s_pointv
{
	double	x;
	double	y;
	double	distance;
	int		wall_hit;
}t_pointv;

typedef struct s_ray
{
	double	x;
	double	y;
	double	distance;
	int		hit_hv;
	char	texture_way;
}t_ray;

typedef struct s_map
{
	int		total_x;
	int		total_y;
	int		width;
	int		height;
	char	**map;
	int		cub_size;
	char	*map_path;

}t_map;

typedef struct s_screen
{
	int		screen_w;
	int		screen_h;
	double	minimap_tile;
	int		map_tile;
}t_screen;

typedef struct s_image
{
	mlx_image_t	*cub_img;
	mlx_image_t	*minimap_img;
}t_image;

typedef struct s_texture
{
	char			**floor_txt;
	char			**ceiling_txt;
	int				floor_color;
	int				ceiling_color;
	mlx_texture_t	*n_wall_txt;
	mlx_texture_t	*s_wall_txt;
	mlx_texture_t	*e_wall_txt;
	mlx_texture_t	*w_wall_txt;
	char			*n_wall_path;
	char			*s_wall_path;
	char			*e_wall_path;
	char			*w_wall_path;
}t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	size;
	int		turn_direction;
	int		walk_direction;
	int		angle;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	int		is_ray_down;
	int		is_ray_up;
	int		is_ray_right;
	int		is_ray_left;
}t_player;

typedef struct s_game
{
	t_player		player;
	t_map			map;
	mlx_t			*mlx;
	t_screen		screen;
	t_image			image;
	t_texture		texture;
	t_pointh		pointh;
	t_pointv		pointv;
	t_ray			ray;
}	t_game;

int			load_option(t_game *game, char *type, char *read_line);
int			char_to_color(char **text, t_game *game);

void		init_cub_file_option(t_game *game);

void		init_data(t_game *game, char *map);

int			init_map(t_game *game);
int			check_map(t_game *game, t_map *map_data, int fd);
int			load_map(t_map *map_data, int fd);
int			check_map_valid(char **map, int rows, int cols);

int			init_player(t_game *game);
void		find_player(t_game *game, t_player *player, \
		t_map *map_data, char **map);

void		error_msg(char *msg, int error_code, t_game *game);
void		free_all_data(t_game *game, int error_code);
void		free_map(t_game *game);

void		gnl_flush(int fd);
void		read_line_free(char *read_line);

int			is_map_option(const char *read_line);
int			map_line_check(const char *read_line);

void		init_minimap(t_game *game);
void		rotate_player(t_player *player);
void		move_player(t_game *game, t_player *player, char ch);
void		player_hook(t_game *game);
int			check_wall(t_game *game, double x, double y);
void		init_rays(t_game *game, t_player *player);
void		draw_ray(t_game *game, t_player *player, double angle);
int			ray_interseption(t_game *game, double x, double y, \
		double angle);
int			calculate_distance(t_player *player, t_pointh *pointh, \
		t_pointv *pointv);
void		ray_horizontal(t_game *game, double x, double y, double angle);
void		ray_vertical(t_game *game, double x, double y, double angle);
void		draw_rectangle(t_game *game, int x, int y, char map_data);
void		put_minimap(t_game *game);
void		put_player(t_game *game);
void		free_all(t_game *game);
int			free_char(char **game);
void		free_option(t_game *game);
void		free_map(t_game *game);
void		set_ray(t_game *game, t_pointh pointh, t_pointv pointv, char hit);
void		render_wall(t_game *game, int ray_num, double angle);
void		put_cub_pixel(t_game *game);
double		normalize_angle(double angle);
void		player_hook_arrow(t_game *game);
void		player_hook_lr(t_game *game);
void		player_hook_fb(t_game *game);
void		player_hook_mouse(t_game *game);
#endif
