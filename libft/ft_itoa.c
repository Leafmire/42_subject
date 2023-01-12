/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:27:44 by gson              #+#    #+#             */
/*   Updated: 2021/05/11 18:47:59 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cvtlen(int n)
{
	int	len;

	len = (n <= 0 ? 1 : 0);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int				len;
	int				minus;
	unsigned int	num;
	char			*a;

	minus = (n >= 0 ? 1 : -1);
	num = (unsigned int)(n > 0 ? n : -n);
	len = ft_cvtlen(n);
	if ((a = (char *)malloc(sizeof(char) * len + 1)) == 0)
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
