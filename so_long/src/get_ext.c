/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:16:04 by gson              #+#    #+#             */
/*   Updated: 2021/11/21 23:32:57 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_ext(char *filename)
{
	static char	buf[MAX_PATH];
	char		*ptr;

	ptr = NULL;
	ptr = ft_strrchr(filename, '.');
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(buf, ptr + 1, ft_strlen(ptr));
	return (buf);
}
