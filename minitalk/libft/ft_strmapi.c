/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:56:23 by gson              #+#    #+#             */
/*   Updated: 2022/02/25 20:39:03 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	temp = (char *)malloc(sizeof(char) * s_len + 1);
	if (temp == 0)
		return (0);
	while (i < s_len)
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
