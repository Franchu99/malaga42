/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:50:52 by frangome          #+#    #+#             */
/*   Updated: 2023/04/19 17:00:01 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlcpy(char *dest, char *src, unsigned int size)
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
