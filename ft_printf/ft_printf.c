/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:50:09 by fran              #+#    #+#             */
/*   Updated: 2023/04/30 15:05:16 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	get_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	if (format == 'p')
		len += ft_print_pointer(va_arg(args, uintptr_t));
	if (format == 'd' || format == 'i')
		len += ft_print_num(va_arg(args, int));
	
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		str_len;
	va_list	args;

	va_start(args, str);
	str_len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str_len += get_format(args, *(str + 1));
			str++;
		}
		else
		{
			write(1, str, 1);
			str_len++;
		}
		str++;
	}
	va_end(args);
	return (str_len);
}

// int	main(void)
// {
// 	char	*ptr;
// 	char	c;

// 	c = 'c';
// 	ptr = &c;
// 	//ft_printf(" %p \n", -1);
// 	printf(" %p \n", 0);
// }