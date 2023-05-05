/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:27:32 by fran              #+#    #+#             */
/*   Updated: 2023/05/05 14:05:00 by fran             ###   ########.fr       */
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
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}

void	remove_line(char *buffer)
{
	int	size;
	int	i;

	size = put_line(buffer);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (i <= (BUFFER_SIZE - size - 1))
			buffer[i] = buffer[i + size + 1];
		else
			buffer[i] = 0;
		i++;
	}
}

void	fill_line(char *line, char *buffer)
{
	int	i;

	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = 0;
}