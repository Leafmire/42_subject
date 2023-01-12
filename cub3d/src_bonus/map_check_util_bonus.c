/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:57:58 by hseong            #+#    #+#             */
/*   Updated: 2022/09/15 16:42:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	is_map_option(const char *read_line)
{
	if (!read_line)
		return (1);
	while (*read_line == ' ')
		++read_line;
	if (ft_isdigit(*read_line))
		return (1);
	return (0);
}

int	map_line_check(const char *read_line)
{
	if (!read_line)
		return (0);
	while (*read_line && *read_line != '\n')
	{
		if (!ft_strchr("013NSWE ", *read_line))
			return (1);
		read_line++;
	}
	return (0);
}
