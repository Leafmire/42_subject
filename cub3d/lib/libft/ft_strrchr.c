/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:28:45 by gson              #+#    #+#             */
/*   Updated: 2022/08/22 21:31:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	int		s_len;

	find = (char)c;
	s_len = ft_strlen(s);
	while (s_len)
	{
		if (s[s_len] == find)
			return ((char *)(s + s_len));
		s_len--;
	}
	if (s[s_len] == find)
		return ((char *)s);
	return (NULL);
}
