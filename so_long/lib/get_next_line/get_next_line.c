/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:07:06 by gson              #+#    #+#             */
/*   Updated: 2021/11/20 05:21:42 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] != 0)
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len] != 0)
		s1_len++;
	while (s2[s2_len] != 0)
		s2_len++;
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!temp)
		return (0);
	ft_memcpy(temp, s1, s1_len);
	ft_memcpy(temp + s1_len, s2, s2_len);
	temp[s1_len + s2_len] = 0;
	return (temp);
}

int	set_line(char **store, char **line, int len)
{
	char	*temp;

	len = 0;
	while ((*store)[len] != '\n' && (*store)[len] != 0)
		len++;
	if ((*store)[len] == '\n')
	{
		*line = ft_substr(*store, 0, len);
		temp = ft_substr(*store, len + 1, ft_strlen(*store) - len);
		free(*store);
		*store = temp;
		if (**store == '\0')
		{
			free(*store);
			*store = NULL;
		}
	}
	else
	{
		*line = ft_strdup(*store);
		free(*store);
		*store = NULL;
		return (0);
	}
	return (1);
}

int	check_read(char **store, int rd, const int fd, char **line)
{
	if (rd == 0 && store[fd] == 0)
	{
		*line = malloc(1);
		**line = '\0';
		return (0);
	}
	if (rd < 0)
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			rd;
	static char	*store[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[rd] = '\0';
		if (store[fd] == 0)
			store[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(store[fd], buff);
			free(store[fd]);
			store[fd] = tmp;
		}
		if (ft_strchr(store[fd], '\n'))
			break ;
		rd = read(fd, buff, BUFFER_SIZE);
	}
	if (check_read(store, rd, fd, line) <= 0)
		return (check_read(store, rd, fd, line));
	return (set_line(&(store[fd]), line, 0));
}
