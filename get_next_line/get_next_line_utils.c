/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:50:01 by frangome          #+#    #+#             */
/*   Updated: 2023/05/03 16:58:10 by frangome         ###   ########.fr       */
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
	while (buffer[i] != 0)
	{
		if (i < lsize)
			buffer[i] = buffer[i + lsize]; 
		else
			buffer[i] = 0;
		i++;
	}
}