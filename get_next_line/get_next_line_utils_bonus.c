/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:14:16 by gson              #+#    #+#             */
/*   Updated: 2021/06/17 16:47:50 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char			*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = 0;
	while (s[slen] != 0)
		slen++;
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
