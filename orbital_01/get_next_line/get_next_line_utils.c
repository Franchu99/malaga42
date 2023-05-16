/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:27:32 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 16:35:00 by frangome         ###   ########.fr       */
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

int	put_line(char *buffer)
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

	size = put_line(buffer);
	i = 0;
	if (is_line(buffer))
	{
		while (buffer[i] != '\0')
		{
			if (i <= (BUFFER_SIZE - size - 1))
				buffer[i] = buffer[i + size + 1];
			else
				buffer[i] = 0;
			i++;
		}
	}
	else
	{
		while (buffer[i] != '\0')
		{
			if (i <= (BUFFER_SIZE - size))
				buffer[i] = buffer[i + size];
			else
				buffer[i] = 0;
			i++;
		}
	}
	}

void	fill_line(char *line, char *buffer)
{
	int	i;

	i = 0;
	while((buffer[i] != '\n' && buffer[i] != '\0') || i < BUFFER_SIZE)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
}