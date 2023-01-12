/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:50:37 by gson              #+#    #+#             */
/*   Updated: 2021/05/06 22:51:08 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*newmemory;
	size_t			i;

	newmemory = s;
	i = 0;
	while (i < n)
	{
		*newmemory = 0;
		newmemory++;
		i++;
	}
}
