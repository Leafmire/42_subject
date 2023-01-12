/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 07:49:04 by gson              #+#    #+#             */
/*   Updated: 2021/11/22 03:55:41 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_player(t_vars *vars)
{
	draw_sprite(vars, &vars->player, vars->ploc.y, vars->ploc.x);
}