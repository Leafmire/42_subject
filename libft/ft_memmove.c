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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*s;
	size_t				i;

	temp = dest;
	s = src;
	i = 0;
	if (temp == NULL && s == NULL)
		return (dest);
	if (dest < src)
		while (i < n)
		{
			temp[i] = s[i];
			i++;
		}
	else
		while (i < n)
		{
			temp[n - i - 1] = s[n - i - 1];
			i++;
		}
	return (dest);
}
