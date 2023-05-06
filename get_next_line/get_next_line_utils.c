/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:27:32 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 19:01:45 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer[i] != 0)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	nline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0' && i < BUFFER_SIZE)
		i++;
	if (buffer[i] == '\n')
		i++;
	return (i);
}

void	remove_line(char *buffer)
{
	int	size;
	int	i;

	size = nline(buffer);
	i = 0;
	
	while (buffer[i] != '\0' && i < BUFFER_SIZE)
	{
		if (i < (BUFFER_SIZE - size))
			buffer[i] = buffer[i + size];
		else
			buffer[i] = 0;
		i++;
	}
}
	

void	fill_line(char *line, char *buffer)
{
	int	i;

	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0' && i < BUFFER_SIZE)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = 0;
}