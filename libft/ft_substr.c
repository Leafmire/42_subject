/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 05:25:45 by gson              #+#    #+#             */
/*   Updated: 2021/05/17 18:55:42 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_get_size(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[start + i] != 0 && i < len)
	{
		count++;
		i++;
	}
	return (count);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	count;

	i = 0;
	if (!s)
		return (0);
	count = ft_get_size(s, start, len);
	if ((str = malloc(sizeof(char) * (count + 1))) == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		str[i] = '\0';
		return (str);
	}
	while (s[start + i] != 0 && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
