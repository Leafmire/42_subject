/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:48 by gson              #+#    #+#             */
/*   Updated: 2021/08/24 00:56:36 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long n, char format, int *cc)
{
	char	*alpha;

	if (format == 'X')
		alpha = "0123456789ABCDEF";
	else
		alpha = "0123456789abcdef";
	if (n < 16)
	{
		ft_putchar(alpha[n], cc);
	}
	else
	{
		ft_putnbr_hex(n / 16, format, cc);
		ft_putnbr_hex(n % 16, format, cc);
	}
}
