/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:21:01 by gson              #+#    #+#             */
/*   Updated: 2021/05/20 15:53:02 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		memerror(char **str, size_t i)
{
	while (i > 0)
	{
		free(str[i]);
		i--;
	}
	free(str[i]);
}

static size_t	wordcount(char const **s, char c, size_t wordc)
{
	while (**s != 0 && **s != c)
	{
		wordc++;
		(*s)++;
	}
	return (wordc);
}

static char		**ft_set_split(char **str, char const *s, char c, size_t wordc)
{
	size_t		i;
	char const	*start;

	i = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			start = s;
			wordc = wordcount(&s, c, wordc);
			if ((str[i] = malloc(sizeof(char) * (wordc + 1))) == 0)
			{
				memerror(str, i);
				return (0);
			}
			ft_strlcpy(str[i], start, wordc + 1);
			i++;
			wordc = 0;
		}
		if (*s != 0)
			s++;
	}
	str[i] = 0;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != 0 && s[i] != c)
				i++;
		}
		if (s[i] != 0)
			i++;
	}
	if ((str = (char **)malloc(sizeof(char*) * (count + 1))) == 0)
		return (0);
	count = 0;
	str = ft_set_split(str, s, c, count);
	return (str);
}
