/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:40 by gson              #+#    #+#             */
/*   Updated: 2021/08/24 02:32:23 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_type(va_list ap, char *format, t_specs *specs, int *cc)
{
	if (*format == 'c' || *format == 's' || *format == '%')
	{
		manage_format_char(ap, specs, *format, cc);
		format++;
	}
	else if (*format == 'd' || *format == 'i')
	{
		manage_format_num(ap, specs, cc);
		format++;
	}
	else if (*format == 'u')
	{
		manage_format_u(ap, specs, cc);
		format++;
	}
	else if (*format == 'p' || *format == 'x' || *format == 'X')
	{
		manage_format_hex(ap, specs, *format, cc);
		format++;
	}
	return (format);
}

char	*set_width(char *format, t_specs *specs)
{
	int	width;
	int	precision;

	width = 0;
	precision = 0;
	while (is_digit(*format))
	{
		width = width * 10 + (*format - '0');
		format++;
	}
	if (*format == '.')
	{
		format++;
		while (is_digit(*format))
		{
			precision = precision * 10 + (*format - '0');
			format++;
		}
	}
	else
		precision = -1;
	specs->width = width;
	specs->precision = precision;
	return (format);
}

char	*set_flag(char *format, t_specs *specs)
{
	if (*format == '-' || *format == '0')
	{
		while (*format == '-' || *format == '0')
		{
			if (*format == '-')
			{
				specs->minus += 1;
				format++;
			}
			else if (*format == '0')
			{
				specs->zero += 1;
				format++;
			}
		}
	}
	return (format);
}

char	*print(va_list ap, char *format, t_specs *specs, int *cc)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_initspecs(specs);
			format = set_flag(format, specs);
			format = set_width(format, specs);
			format = set_type(ap, format, specs, cc);
		}
		else
		{
			ft_putchar(*format, cc);
			format++;
		}
	}
	return (format);
}

int	ft_printf(const char *format, ...)
{
	int			char_count;
	char		*str;
	t_specs		specs;
	va_list		ap;

	va_start(ap, format);
	char_count = 0;
	str = ft_strdup(format);
	print(ap, str, &specs, &char_count);
	va_end(ap);
	free(str);
	return (char_count);
}
