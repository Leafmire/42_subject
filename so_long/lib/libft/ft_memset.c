/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:21:48 by gson              #+#    #+#             */
/*   Updated: 2021/05/03 15:22:37 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*newmemory;
	unsigned char	fill;
	size_t			i;

	newmemory = s;
	fill = c;
	i = 0;
	while (i < n)
	{
		*newmemory = fill;
		newmemory++;
		i++;
	}
	return (s);
}
