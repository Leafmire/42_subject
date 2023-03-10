/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:40:41 by gson              #+#    #+#             */
/*   Updated: 2022/08/22 21:31:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	index;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		tmp[index] = s[start + index];
		index++;
	}
	tmp[index] = 0;
	return (tmp);
}
