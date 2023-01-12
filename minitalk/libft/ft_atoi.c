/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 00:18:17 by gson              #+#    #+#             */
/*   Updated: 2021/05/07 00:39:41 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (minus * num);
}
