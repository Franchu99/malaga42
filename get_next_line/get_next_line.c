/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:15:20 by fran              #+#    #+#             */
/*   Updated: 2023/05/08 20:21:58 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	empty_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length] != 0 && str[length] != '\n' )
		length++;
	if (str[length] == '\n')
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size_s1;
	int		size_s2;
	int		c;

	size_s1 = ft_strlen(s1);
	size_s2 = nline((char *)s2);
	res = malloc(size_s1 + size_s2 + 1);
	if (!res)
		return (NULL);
	c = -1;
	while (++c < size_s1)
		res[c] = s1[c];
	c = -1;
	while (++c < size_s2 && s2[c] != '\n')
		res[c + size_s1] = s2[c];
	if (c < size_s2 && s2[c] == '\n')
	{
		res[c + size_s1] = '\n';
		c++;
	}
	res[c + size_s1] = '\0';
	free((char *)s1);
	return (res);
}

char	*check_line(char *line, char *buffer, int fd, int i)
{
	if (is_line(buffer))
	{
		remove_line(buffer);
		return (line);
	}
	else
		return (no_line(line, buffer, fd, i));
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	buffer[BUFFER_SIZE];

	i = 0;
	if (buffer[0] != 0)
	{
		line = (char *)malloc(sizeof(char) * (nline(buffer) + 1));
		if (!line)
			return (0);
		fill_line(line, buffer);
	}
	else
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
		{
			empty_buffer(buffer);
			return (0);
		}
		line = (char *)malloc(sizeof(char) * (nline(buffer) + 1));
		if (!line)
			return (0);
		fill_line(line, buffer);
	}
	return (check_line(line, buffer, fd, i));
}
