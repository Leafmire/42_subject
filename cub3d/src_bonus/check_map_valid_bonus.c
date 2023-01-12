/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 05:07:42 by gson              #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../include/cub3d_bonus.h"

int	check_top_bottom(char **map, int rows, int cols, int *yx)
{
	if (yx[0] == 0 || yx[0] == rows - 1)
	{
		if (map[yx[0]][yx[1]] != '1')
			return (1);
	}
	else
	{
		if ((yx[1] == 0 || yx[1] == cols - 1) && map[yx[0]][yx[1]] != '1')
			return (1);
		else if ((map[yx[0]][yx[1] - 1] == ' ' || map[yx[0]][yx[1] + 1] == ' ') \
			&& map[yx[0]][yx[1]] != '1')
			return (1);
	}
	return (0);
}

int	check_map_valid(char **map, int rows, int cols)
{
	int	i;
	int	j;
	int	yx[2];

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			yx[0] = i;
			yx[1] = j;
			if (map[i][j] != ' ')
			{
				if (check_top_bottom(map, rows, cols, yx))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
