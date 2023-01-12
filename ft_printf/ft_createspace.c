/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:29 by gson              #+#    #+#             */
/*   Updated: 2021/08/22 11:04:39 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_space_left(t_specs *specs, int len, int *cc)
{
	int	width;

	width = specs->width - len;
	if (specs->zero > 0)
	{
		while (width > 0)
		{
			write(1, "0", 1);
			(*cc)++;
			width--;
		}
	}
	else
	{
		while (width > 0)
		{
			write(1, " ", 1);
			(*cc)++;
			width--;
		}
	}	
}

void	create_space_left_i(t_specs *specs, int len, int *cc, int n)
{
	int	width;

	width = specs->width - len;
	if (specs->zero > 0)
	{
		if (n < 0 && specs->precision == -1)
			ft_putstr("-", cc);
		while (width > 0)
		{
			if (specs->precision == -1)
				ft_putstr("0", cc);
			else
				ft_putstr(" ", cc);
			width--;
		}
	}
	else
	{
		while (width > 0)
		{
			ft_putstr(" ", cc);
			width--;
		}
	}	
}

void	create_space_left_ui(t_specs *specs, int len, int *cc)
{
	int	width;

	width = specs->width - len;
	if (specs->zero > 0)
	{
		while (width > 0)
		{
			if (specs->precision == -1)
				ft_putstr("0", cc);
			else
				ft_putstr(" ", cc);
			width--;
		}
	}
	else
	{
		while (width > 0)
		{
			ft_putstr(" ", cc);
			width--;
		}
	}	
}

void	create_space_right(t_specs *specs, int len, int *cc)
{
	int	width;

	width = specs->width - len;
	if (specs->zero > 0)
	{
		while (width > 0)
		{
			write(1, "0", 1);
			(*cc)++;
			width--;
		}
	}
	else
	{
		while (width > 0)
		{
			write(1, " ", 1);
			(*cc)++;
			width--;
		}
	}	
}
