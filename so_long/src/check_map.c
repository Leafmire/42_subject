/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 08:00:08 by gson              #+#    #+#             */
/*   Updated: 2021/11/21 23:04:09 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_wall(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.rows)
	{
		if (vars->map.data[i][0] != '1' ||
			vars->map.data[i][vars->map.cols - 1] != '1')
			error_out("This map is not surrounded by walls.", vars);
		i++;
	}
	j = 0;
	while (j < vars->map.cols)
	{
		if (vars->map.data[0][j] != '1' ||
			vars->map.data[vars->map.rows - 1][j] != '1')
			error_out("This map is not surrounded by walls.", vars);
		j++;
	}
}

void	check_square(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.rows - 1)
	{
		if (ft_strlen(vars->map.data[i]) != ft_strlen(vars->map.data[i + 1]))
			error_out("This map is not square.", vars);
		i++;
	}
}

void	count_element(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->map.rows)
	{
		j = 0;
		while (j < vars->map.cols)
		{
			if (vars->map.data[i][j] == 'C')
				vars->elem.is_c = 1;
			else if (vars->map.data[i][j] == 'E')
				vars->elem.is_e = 1;
			else if (vars->map.data[i][j] == 'P')
				vars->elem.is_p = 1;
			else if (vars->map.data[i][j] != '1' &&
				vars->map.data[i][j] != '0')
				vars->elem.is_o = 1;
			j++;
		}
		i++;
	}
}

static void	origin_composition(t_vars *vars, int i, int j)
{
	if (vars->map.data[i][j] == 'P')
	{
		vars->ploc.y = i * 24;
		vars->ploc.x = j * 24;
	}
	else if (vars->map.data[i][j] == 'C')
	{
		lstadd_back(&vars->gloc, lstnew(i * 24, j * 24));
	}
}

void	sprite_composition(t_vars *vars)
{
	int		i;
	int		j;
	t_goal	*node;

	i = 0;
	while (i < vars->map.rows)
	{
		j = 0;
		while (j < vars->map.cols)
		{
			origin_composition(vars, i, j);
			j++;
		}
		i++;
	}
	node = vars->gloc;
	vars->gloc = vars->gloc->next;
	free(node);
}
