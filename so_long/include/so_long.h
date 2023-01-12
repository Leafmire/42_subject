/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 05:59:59 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 05:47:49 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILEPIXEL 24
# define MAX_PATH 256
# define EXT "ber"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "./keybinding_mac.h"

typedef struct s_elem {
	int	is_c;
	int	is_e;
	int	is_p;
	int	is_o;
}	t_elem;

typedef struct s_map {
	int		cols;
	int		rows;
	char	**data;
}	t_map;

typedef struct s_goal {
	int				is_collect;
	int				x;
	int				y;
	struct s_goal	*next;
}	t_goal;

typedef struct s_loc {
	int	x;
	int	y;
}	t_loc;

typedef struct s_img
{
	int				size_line;
	int				bpp;
	int				endian;
	int				width;
	int				height;
	char			*data;
	void			*img_ptr;
}	t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_img	mlx_img;
	int		width;
	int		height;
	int		up;
	int		down;
	int		left;
	int		right;
	int		*count;
	int		all_collect;
	t_img	tile;
	t_img	wall;
	t_img	goal;
	t_img	stair;
	t_img	player;
	t_map	map;
	t_loc	ploc;
	t_goal	*gloc;
	t_elem	elem;
}	t_vars;

int				map_open(int fd, char *file);
int				map_read(char *file, t_vars *vars);
int				init_vars(t_vars *vars);
int				init_map(t_vars *vars);
char			*get_ext(char *filename);
void			sprite_composition(t_vars *vars);
void			check_square(t_vars *vars);
void			count_element(t_vars *vars);
void			check_wall(t_vars *vars);
void			draw_map(t_vars *vars);
void			set_image(t_vars *vars);
unsigned int	mlx_get_pixel(t_img *img, int y, int x);
void			mlx_draw_pixel(t_img *mlx_img, int y, int x,
					unsigned int color);
unsigned int	mlx_rgb_to_int(int t, int r, int g, int b);
void			draw_sprite(t_vars *vars, t_img *img, int y, int x);
void			put_player(t_vars *vars);
void			put_goal(t_vars *vars);
int				ft_exit(t_vars *vars);
int				error_out(char *message, t_vars *vars);
void			update_player(t_vars *vars);
void			update_collect(t_vars *vars);
void			check_collect_all(t_vars *vars);
void			check_complete(t_vars *vars);
t_goal			*lstnew(int y, int x);
void			lstadd_back(t_goal **lst, t_goal *new);
void			lstclear(t_goal **lst);

#endif
