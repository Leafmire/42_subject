/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initspecs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:38 by gson              #+#    #+#             */
/*   Updated: 2021/08/19 17:50:01 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initspecs(t_specs *specs)
{
	specs->zero = 0;
	specs->minus = 0;
	specs->width = 0;
	specs->precision = 0;
}
