/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:15:20 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 12:12:55 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
    char		*line;
    static char	buffer[BUFFER_SIZE];
	
	if (buffer)
	{
		line = (char *)malloc(sizeof(char) * put_line(buffer));
		fill_line(line, buffer);
	}
	else
	{
		if (read(fd, buffer, BUFFER_SIZE) == 0)
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
		while(read(fd, buffer, BUFFER_SIZE) && !is_line(buffer))
		{
			line = ft_strjoin(line, buffer);
			remove_line(buffer);
		}
		line = ft_strjoin(line, buffer);
		remove_line(buffer);
		return (line);
	}
}
