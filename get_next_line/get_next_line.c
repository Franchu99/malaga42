/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:09:51 by frangome          #+#    #+#             */
/*   Updated: 2023/05/03 17:02:15 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[100];
	char			*line;
	int				lsize;
	int				i;
	int				bsize;
	
	bsize = 100;
	while(read(fd, buffer, bsize))
	{
		lsize = get_size(buffer);
		line = (char *)malloc(sizeof(char) * (lsize + 1));
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
