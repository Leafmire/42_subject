/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:54:04 by gson              #+#    #+#             */
/*   Updated: 2021/05/03 19:18:00 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		(((unsigned char *)dest)[i] = ((unsigned char *)src)[i]);
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			i++;
			return (&((unsigned char *)dest)[i]);
		}
		i++;
	}
	return (NULL);
}
