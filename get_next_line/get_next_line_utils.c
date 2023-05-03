/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:50:01 by frangome          #+#    #+#             */
/*   Updated: 2023/05/03 23:22:11 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_size(char *buffer)
{
	int len;

	len = 0;
	while (buffer[len] != '\n')
		len++;
	return (len);
}

void remove_line(char *buffer, int lsize)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (i < (BUFFER_SIZE - lsize - 1))
			buffer[i] = buffer[i + lsize + 2];
		else
			buffer[i] = 0;
		i++;
	}
}