/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:06:39 by fran              #+#    #+#             */
/*   Updated: 2023/05/01 18:23:37 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_num(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	len = 0;
	while (str[len] != '\0')
	{
		ft_print_char(str[len]);
		len++;
	}
	free(str);
	return (len);
}

int	ft_print_unsigned(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_long_itoa(num);
	len = 0;
	while (str[len] != '\0')
	{
		ft_print_char(str[len]);
		len++;
	}
	free(str);
	return (len);
}
