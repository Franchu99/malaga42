/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:07:39 by frangome          #+#    #+#             */
/*   Updated: 2023/04/19 15:49:08 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, unsigned int n)
{
	unsigned int	count;
	char			*str2;

	str2 = str;
	count = 0;
	while (count < n)
	{
		*(str2 + count) = (unsigned char)c;
		count++;
	}
	return (str);
}
