/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:27:32 by fran              #+#    #+#             */
/*   Updated: 2023/05/31 15:40:10 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_line(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != 0)
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
	while (i < BUFFER_SIZE && buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (i < BUFFER_SIZE && buffer[i] == '\n')
		i++;
	return (i);
}

void	remove_line(char *buffer)
{
	int	size;
	int	i;

	size = nline(buffer);
	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\0')
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
	while (i < BUFFER_SIZE && buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (i < BUFFER_SIZE && buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = 0;
}

char	*no_line(char *line, char *buffer, int fd, int i)
{
	remove_line(buffer);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i < 0)
	{
		free(line);
		empty_buffer(buffer);
		return (0);
	}
	while (i && !is_line(buffer))
	{
		line = ft_strjoin(line, buffer);
		remove_line(buffer);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(line);
			empty_buffer(buffer);
			return (0);
		}
	}
	if (i)
		line = ft_strjoin(line, buffer);
	remove_line(buffer);
	return (line);
}
