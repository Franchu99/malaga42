/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:59:19 by frangome          #+#    #+#             */
/*   Updated: 2023/04/22 17:59:09 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	if (!dest && !src)
		return (0);
	while (c < n)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		c++;
	}
	return (dest - c);
}
