/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:49 by gson              #+#    #+#             */
/*   Updated: 2021/08/24 00:56:48 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *cc)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10, cc);
		ft_putnbr(8, cc);
		return ;
	}
	if (n < 0)
		n = -n;
	if (n < 10)
	{
		ft_putchar(n + '0', cc);
	}
	else
	{
		ft_putnbr(n / 10, cc);
		ft_putnbr(n % 10, cc);
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *cc)
{
	if (n < 10)
	{
		ft_putchar(n + '0', cc);
	}
	else
	{
		ft_putnbr_unsigned(n / 10, cc);
		ft_putnbr_unsigned(n % 10, cc);
	}
}
