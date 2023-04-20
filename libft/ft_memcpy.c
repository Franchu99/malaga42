/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:59:19 by frangome          #+#    #+#             */
/*   Updated: 2023/04/20 18:06:53 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, void *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (c < n)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		c++;
	}
	return ((void *)(dest - c));
}
