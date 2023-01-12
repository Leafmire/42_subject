/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:27:30 by gson              #+#    #+#             */
/*   Updated: 2022/08/22 21:31:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				index;
	const unsigned char	*s1_tmp;
	const unsigned char	*s2_tmp;

	index = 0;
	s1_tmp = (const unsigned char *)s1;
	s2_tmp = (const unsigned char *)s2;
	while ((s1[index] || s2[index]) && (index < n))
	{
		if (s1_tmp[index] != s2_tmp[index])
			return (s1_tmp[index] - s2_tmp[index]);
		index++;
	}
	return (0);
}
