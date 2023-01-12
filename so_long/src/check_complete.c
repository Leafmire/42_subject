/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mission_complete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 07:26:11 by gson              #+#    #+#             */
/*   Updated: 2021/11/20 07:42:43 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_complete(t_vars *vars)
{
	int		i;
	int		j;

	i = vars->ploc.y / 24;
	j = vars->ploc.x / 24;
	if (vars->map.data[i][j] == 'E')
	{
		if (vars->all_collect == 1)
			ft_exit(vars);
	}
}
