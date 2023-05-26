/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:30:57 by frangome          #+#    #+#             */
/*   Updated: 2023/05/26 17:55:12 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len_hexa(unsigned int num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_print_hexa(unsigned int num)
{
	int	len;

	len = get_len_hexa(num);
	if (num >= 16)
	{
		ft_print_hexa(num / 16);
		ft_print_hexa(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char((int)num + '0');
		else
			ft_print_char((int)num - 10 + 'a');
	}
	return (len);
}

int	ft_print_upper_hexa(unsigned int num)
{
	int	len;

	len = get_len_hexa(num);
	if (num >= 16)
	{
		ft_print_upper_hexa(num / 16);
		ft_print_upper_hexa(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char((int)num + '0');
		else
			ft_print_char((int)num - 10 + 'A');
	}
	return (len);
}
