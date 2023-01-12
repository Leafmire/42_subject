/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 04:58:35 by gson              #+#    #+#             */
/*   Updated: 2021/05/07 05:10:57 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = malloc(size * number);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, size * number);
	return (ptr);
}
