/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatthree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:34 by gson              #+#    #+#             */
/*   Updated: 2021/08/24 00:26:01 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen_unsigned(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	manage_format_x(va_list ap, t_specs *specs, char format, int *cc)
{
	unsigned int	num;
	int				len;

	num = va_arg(ap, unsigned int);
	len = numlen_unsigned(num);
	if (specs->precision > len)
		len = specs->precision;
	if (specs->precision == 0 && num == 0)
		len = 0;
	if (specs->minus == 0)
		create_space_left_ui(specs, len, cc);
	while (specs->precision > numlen_unsigned(num))
	{
		ft_putstr("0", cc);
		specs->precision--;
	}
	if (specs->precision == 0 && num == 0)
		;
	else
		ft_putnbr_hex(num, format, cc);
	if (specs->minus > 0)
		create_space_right(specs, len, cc);
}

void	manage_format_p(va_list ap, t_specs *specs, char format, int *cc)
{
	unsigned long	num;
	int				len_origin;
	int				len;

	num = va_arg(ap, unsigned long);
	len_origin = numlen_unsigned(num);
	len = len_origin;
	len += 2;
	if (specs->minus == 0)
		create_space_left(specs, len, cc);
	ft_putstr("0x", cc);
	ft_putnbr_hex(num, format, cc);
	if (specs->minus > 0)
		create_space_right(specs, len, cc);
}

void	manage_format_hex(va_list ap, t_specs *specs, char format, int *cc)
{
	if (format == 'x' || format == 'X')
		manage_format_x(ap, specs, format, cc);
	else if (format == 'p')
		manage_format_p(ap, specs, format, cc);
}
