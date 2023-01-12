/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:22:51 by gson              #+#    #+#             */
/*   Updated: 2021/05/06 17:08:03 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == src || n == 0)
		return (dst);
	if (dst < src)
	{
		new_dst = (unsigned char *)dst;
		new_src = (unsigned char *)src;
		while (n--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst = (unsigned char *)dst + (n - 1);
		new_src = (unsigned char *)src + (n - 1);
		while (n--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
