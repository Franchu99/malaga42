/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:21:30 by frangome          #+#    #+#             */
/*   Updated: 2023/04/19 17:41:38 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned long	i;
	unsigned long	j;
	unsigned long	result;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (size > i)
		result = i + j;
	else
		result = j + size;
	count = 0;
	while (src[count] != 0 && i < (size - 1))
	{
		dest[i + count] = src[count];
		++count;
	}
	dest[i + count] = 0;
	return (result);
}
