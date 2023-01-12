/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:44:50 by gson              #+#    #+#             */
/*   Updated: 2022/02/25 20:39:00 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		cmp;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		if (big[i] == little[0])
		{
			if (len - i < ft_strlen(little))
				return (0);
			cmp = ft_strncmp(&big[i], little, ft_strlen(little));
			if (cmp == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
