/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:17:51 by gson              #+#    #+#             */
/*   Updated: 2021/05/06 19:31:51 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	j = ft_strlen(dest);
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	while (src[i] != 0 && (i + destlen + 1) < size)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	if (destlen >= size)
		return (size + srclen);
	else
		return (destlen + srclen);
}
