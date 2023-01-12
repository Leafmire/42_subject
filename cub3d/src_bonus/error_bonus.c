/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:21:51 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	error_msg(char *msg, int error_code, t_game *game)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	free_all_data(game, error_code);
}

void	free_all_data(t_game *game, int error_code)
{
	if (error_code == 3)
		free_option(game);
	if (error_code >= 4 && error_code <= 6)
		free_map(game);
	exit(error_code);
}
