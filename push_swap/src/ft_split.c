/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:21:01 by gson              #+#    #+#             */
/*   Updated: 2022/02/07 15:55:41 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_splitcpy(char *dest, char const *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

static char	**ft_set_split(char **str, char const *s, char c, int count)
{
	int			i;
	char const	*start;
	int			wordc;

	i = 0;
	wordc = 0;
	while (i < count && *s != 0)
	{
		if (*s != c)
		{
			start = s;
			while (*s != c)
			{
				wordc++;
				s++;
			}
			str[i] = malloc(sizeof(char) * (wordc + 1));
			ft_splitcpy(str[i], start, wordc + 1);
			i++;
			wordc = 0;
		}
		s++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			count++;
			while (i < ft_strlen(s) && s[i] != c)
				i++;
		}
		i++;
	}
	str = (char **)malloc(sizeof(char *) * (count + 1));
	str = ft_set_split(str, s, c, count);
	return (str);
}
