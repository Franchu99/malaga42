/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:51:49 by frangome          #+#    #+#             */
/*   Updated: 2023/04/20 17:54:52 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	count;
	char			*str2;

	str2 = (char *)s;
	count = 0;
	while (count < n)
	{
		if (*(unsigned char *)str2 == (unsigned char)c)
			return ((void *)str2);
		str2++;
		count++;
	}
	return (0);
}
