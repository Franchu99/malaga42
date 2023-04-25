/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:50:52 by frangome          #+#    #+#             */
/*   Updated: 2023/04/25 21:16:20 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned long	i;

	i = 0;
	while (src[i] != 0)
		i++;
	count = 0;
	if (size == 0)
		return (i);
	while (src[count] != 0 && count < (size - 1))
	{
		dest[count] = src[count];
		++count;
	}
	dest[count] = 0;
	return (i);
}
