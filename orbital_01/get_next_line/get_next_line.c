/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:15:20 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 16:04:39 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

unsigned int	ft_strlen(const char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length] != 0 && str[length] != '\n' && length < BUFFER_SIZE)
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
	size_s2 = ft_strlen(s2);
	res = malloc(size_s1 + size_s2 + 1);
	if (!res)
		return (NULL);
	c = 0;
	while (c < size_s1)
	{
		res[c] = s1[c];
		c++;
	}
	c = 0;
	while (c < size_s2 && s2[c] != '\n')
	{
		res[c + size_s1] = s2[c];
		c++;
	}
	res[c + size_s1] = '\0';
	free((char *)s1);
	return (res);
}

char	*get_next_line(int fd)
{
    char		*line;
    static char	buffer[BUFFER_SIZE];
	int			i;
	
	if (buffer[0] != 0)
	{
		line = (char *)malloc(sizeof(char) * put_line(buffer));
		fill_line(line, buffer);
	}
	else
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (0);
		line = (char *)malloc(sizeof(char) * put_line(buffer));
		fill_line(line, buffer);
	}
	if (is_line(buffer))
	{
		remove_line(buffer);
		return (line);
	}
	else
	{
		i = read(fd, buffer, BUFFER_SIZE);
		while(i > 0 && !is_line(buffer))
		{
			line = ft_strjoin(line, buffer);
			remove_line(buffer);
			i = read(fd, buffer, BUFFER_SIZE);
		}
		if (i)
			line = ft_strjoin(line, buffer);
		remove_line(buffer);
		return (line);
	}
}
