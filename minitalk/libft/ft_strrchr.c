/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:43:18 by gson              #+#    #+#             */
/*   Updated: 2022/02/25 20:38:52 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i > 0)
	{
		if ((unsigned char)s[i - 1] == (unsigned char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (0);
}
