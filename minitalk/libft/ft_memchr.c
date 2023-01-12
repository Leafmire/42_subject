/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:24:42 by gson              #+#    #+#             */
/*   Updated: 2021/05/06 12:25:10 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (unsigned char)value)
			return (&temp[i]);
		i++;
	}
	return (0);
}
