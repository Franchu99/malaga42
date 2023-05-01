/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:12:36 by frangome          #+#    #+#             */
/*   Updated: 2023/05/01 18:21:47 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

long	get_size_long(long n)
{
	int	c;

	if (n == 0)
		return (1);
	c = 0;
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*put_str(char *str, long n, long neg)
{
	long	size;
	long	c;

	size = get_size_long(n);
	if (neg)
		size = get_size_long(n) + 1;
	str[size] = 0;
	c = 0;
	while (c < size)
	{
		str[size - c - 1] = (n % 10) + 48;
		n /= 10;
		c++;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char	*ft_long_itoa(long n)
{
	char	*str;
	long	size;
	long	neg;

	neg = 0;
	size = get_size_long(n);
	if (n < 0)
	{
		n *= -1;
		size = get_size_long(n) + 1;
		neg = 1;
	}
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	str = put_str(str, n, neg);
	return (str);
}
