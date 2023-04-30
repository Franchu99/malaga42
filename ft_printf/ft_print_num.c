/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:06:39 by fran              #+#    #+#             */
/*   Updated: 2023/04/30 22:45:45 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	num_len(int num)
{
	int i;

	i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

int ft_print_num(int num)
{
	int		len;
	char	*str;
	
	str = ft_itoa(num);
	len = num_len(num);
	while (*str != '\0')
	{
		ft_print_char(*str);
		str++;
	}
    return(len);
}