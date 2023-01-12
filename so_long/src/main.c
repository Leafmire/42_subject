/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:07:45 by gson              #+#    #+#             */
/*   Updated: 2021/11/21 22:57:11 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == UP)
		vars->up = 1;
	if (keycode == DOWN)
		vars->down = 1;
	if (keycode == LEFT)
		vars->left = 1;
	if (keycode == RIGHT)
		vars->right = 1;
	update_player(vars);
	update_collect(vars);
	check_collect_all(vars);
	draw_map(vars);
	check_complete(vars);
	return (0);
}

int	ft_key_release(int keycode, t_vars *vars)
{
	if (keycode == UP)
		vars->up = 0;
	if (keycode == DOWN)
		vars->down = 0;
	if (keycode == LEFT)
		vars->left = 0;
	if (keycode == RIGHT)
		vars->right = 0;
	return (0);
}

int	ft_exit(t_vars *vars)
{
	if (vars->gloc)
		lstclear(&vars->gloc);
	if (vars->mlx)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	if (argc != 2)
	{
		return (0);
	}
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == 0)
		ft_exit(vars);
	init_vars(vars);
	map_read(argv[1], vars);
	init_map(vars);
	set_image(vars);
	draw_map(vars);
	mlx_hook(vars->win, KEYPRESS, 1L << 0, ft_key_press, vars);
	mlx_hook(vars->win, KEYRELEASE, 1L << 1, ft_key_release, vars);
	mlx_hook(vars->win, EXITPRESS, 0, ft_exit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
