/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:27:44 by gson              #+#    #+#             */
/*   Updated: 2021/11/13 22:30:59 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cvtlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	check_minus(int minus, int n)
{
	if (n >= 0)
		minus = 1;
	else
		minus = -1;
	return (minus);
}

unsigned int	check_num(unsigned int num, unsigned int n)
{
	if (n > 0)
		num = n;
	else
		num = -n;
	return (num);
}

char	*ft_itoa(int n)
{
	int				len;
	int				minus;
	unsigned int	num;
	char			*a;

	minus = 0;
	num = 0;
	minus = check_minus(minus, n);
	num = check_num(num, n);
	len = ft_cvtlen(n);
	a = (char *)malloc(sizeof(char) * len + 1);
	if (a == 0)
		return (0);
	a[len--] = '\0';
	while (len >= 0)
	{
		a[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	if (minus == -1)
		a[0] = '-';
	return (a);
}
