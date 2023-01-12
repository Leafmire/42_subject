/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:24:24 by gson              #+#    #+#             */
/*   Updated: 2021/05/17 19:01:34 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	i;
	size_t	s1_len;
	size_t	set_len;

	i = 0;
	if (!s1 || !set)
		return (0);
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	while (s1[i] != 0 && ft_memchr(set, s1[i], set_len))
		i++;
	while (s1_len - 1 > i && ft_memchr(set, s1[s1_len - 1], set_len))
		s1_len--;
	if ((temp = (char *)malloc(sizeof(char) * (s1_len - i + 1))) == 0)
		return (0);
	ft_strlcpy(temp, &s1[i], s1_len - i + 1);
	return (temp);
}
