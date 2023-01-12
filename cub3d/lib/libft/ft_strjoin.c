/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:06:50 by gson              #+#    #+#             */
/*   Updated: 2022/08/22 21:31:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, s1, ft_strlen(s1) + 1);
	ft_strlcpy(tmp + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (tmp);
}
