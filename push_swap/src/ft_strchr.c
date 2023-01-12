/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:35:28 by gson              #+#    #+#             */
/*   Updated: 2022/02/04 02:35:59 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[slen]);
	while (s[i] != 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
