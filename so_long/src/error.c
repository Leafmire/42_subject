/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:34:51 by gson              #+#    #+#             */
/*   Updated: 2021/11/21 10:35:00 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_out(char *message, t_vars *vars)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(message, 1);
	ft_exit(vars);
	return (0);
}
