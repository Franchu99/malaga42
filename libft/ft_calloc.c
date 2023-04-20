/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:38:29 by frangome          #+#    #+#             */
/*   Updated: 2023/04/20 17:36:18 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	char				*array;
	unsigned int		c;

	array = malloc(nmemb * size);
	c = 0;
	while (c < size * nmemb)
	{
		array[c] = 0;
		c = c + size;
	}
	return ((void *)array);
}
