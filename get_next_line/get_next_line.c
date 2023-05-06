/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:15:20 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 18:49:20 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
    char		*line;
    static char	buffer[BUFFER_SIZE];
	int			i;
	
	if (buffer[0] != 0)
	{
		line = (char *)malloc(sizeof(char) * nline(buffer));
		fill_line(line, buffer);
	}
	else
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (0);
		line = (char *)malloc(sizeof(char) * nline(buffer));
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
		while(i && !is_line(buffer))
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
