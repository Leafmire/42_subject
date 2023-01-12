/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:31 by gson              #+#    #+#             */
/*   Updated: 2021/08/22 05:50:17 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_format_c(va_list ap, t_specs *specs, int *cc)
{
	char	c;

	c = va_arg(ap, int);
	if (specs->minus == 0)
		create_space_left(specs, 1, cc);
	write(1, &c, 1);
	(*cc)++;
	if (specs->minus > 0)
		create_space_right(specs, 1, cc);
}

void	manage_format_sp(t_specs *specs, int *cc, char *s)
{
	int		len;

	len = ft_strlen(s);
	if (specs->precision < len)
		len = specs->precision;
	if (specs->minus == 0)
		create_space_left(specs, len, cc);
	while (*s && specs->precision > 0)
	{
		write(1, &*s, 1);
		(*cc)++;
		s++;
		specs->precision--;
	}
	if (specs->minus > 0)
		create_space_right(specs, len, cc);
}

void	manage_format_s(va_list ap, t_specs *specs, int *cc)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (specs->precision >= 0)
	{
		manage_format_sp(specs, cc, s);
		return ;
	}
	if (specs->minus == 0)
		create_space_left(specs, len, cc);
	ft_putstr(s, cc);
	if (specs->minus > 0)
		create_space_right(specs, len, cc);
}

void	manage_format_percent(t_specs *specs, int *cc)
{
	char	c;

	c = '%';
	if (specs->minus == 0)
		create_space_left(specs, 1, cc);
	write(1, &c, 1);
	(*cc)++;
	if (specs->minus > 0)
		create_space_right(specs, 1, cc);
}

void	manage_format_char(va_list ap, t_specs *specs, char format, int *cc)
{
	if (format == 'c')
		manage_format_c(ap, specs, cc);
	else if (format == 's')
		manage_format_s(ap, specs, cc);
	else if (format == '%')
		manage_format_percent(specs, cc);
}
