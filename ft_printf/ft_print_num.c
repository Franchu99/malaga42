/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:06:39 by fran              #+#    #+#             */
/*   Updated: 2023/04/30 15:20:49 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (str)
	{
		ft_print_char(*str);
		str++;
	}
    return(len);
}