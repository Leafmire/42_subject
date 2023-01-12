/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formattwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:36 by gson              #+#    #+#             */
/*   Updated: 2021/08/22 11:05:20 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(int n)
{
	int	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static int	numlen_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	manage_format_nump(t_specs *specs, int *cc, int num)
{
	int	len;
	int	ext;

	len = numlen(num);
	ext = 0;
	if (specs->precision >= len)
	{
		if (num < 0)
			specs->precision++;
		ext = specs->precision - len;
	}
	if (specs->minus == 0)
		create_space_left_i(specs, len + ext, cc, num);
	if (num < 0 && (specs->zero == 0
			|| (specs->precision >= 0 && specs->zero > 0)))
		ft_putstr("-", cc);
	while (specs->precision - len > 0)
	{
		ft_putstr("0", cc);
		specs->precision--;
	}
	ft_putnbr(num, cc);
	if (specs->minus > 0)
		create_space_right(specs, len + ext, cc);
}

void	manage_format_num(va_list ap, t_specs *specs, int *cc)
{
	int	num;
	int	len;

	num = va_arg(ap, int);
	len = numlen(num);
	if (specs->precision > 0)
	{
		manage_format_nump(specs, cc, num);
		return ;
	}
	if (specs->precision == 0 && num == 0)
		len = 0;
	if (specs->minus == 0)
		create_space_left_i(specs, len, cc, num);
	if (num < 0 && (specs->zero == 0
			|| (specs->precision >= 0 && specs->zero > 0)))
		ft_putstr("-", cc);
	if (specs->precision == 0 && num == 0)
		;
	else
		ft_putnbr(num, cc);
	if (specs->minus > 0)
		create_space_right(specs, len, cc);
}

void	manage_format_u(va_list ap, t_specs *specs, int *cc)
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
		ft_putnbr_unsigned(num, cc);
	if (specs->minus > 0)
		create_space_right(specs, len, cc);
}
