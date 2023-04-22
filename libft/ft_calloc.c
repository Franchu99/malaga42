/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:38:29 by frangome          #+#    #+#             */
/*   Updated: 2023/04/22 17:47:15 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*array;

	array = malloc(nmemb * size);
	if (array == 0)
		return (array);
	ft_bzero(array, nmemb * size);
	return (array);
}
