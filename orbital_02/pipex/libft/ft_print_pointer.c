/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:11:32 by fran              #+#    #+#             */
/*   Updated: 2023/05/26 17:56:43 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

void	write_pointer(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		write_pointer(ptr / 16);
		write_pointer(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_print_char(ptr + '0');
		else
			ft_print_char(ptr - 10 + 'a');
	}
}

int	ft_print_pointer(uintptr_t ptr)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		write_pointer(ptr);
		len += get_len(ptr);
	}
	return (len);
}
