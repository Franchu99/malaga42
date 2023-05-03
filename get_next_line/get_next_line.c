/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:09:51 by frangome          #+#    #+#             */
/*   Updated: 2023/05/03 22:57:34 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[100];
	char			*line;
	int				lsize;
	int				i;

	if(!buffer)
		return (0);
	while(read(fd, buffer, BUFFER_SIZE))
	{
		lsize = get_size(buffer);
		line = (char *)malloc(sizeof(char) * (lsize + 1));
		if (!line)
			return (0);
		i = 0;
		while (i < lsize)
		{
			line[i] = buffer[i];
			i++;
		}
		line[i] = 0;
		remove_line(buffer, lsize);
		return (line);
	}
	return (0);
}
