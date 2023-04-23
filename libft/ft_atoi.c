/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:49:05 by frangome          #+#    #+#             */
/*   Updated: 2023/04/23 10:45:21 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	c;
	int	num;
	int	sign;

	sign = 1;
	c = 0;
	num = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\t'
		|| str[c] == '\r' || str[c] == '\v' || str[c] == '\f')
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while ((str[c] >= '0' && str[c] <= '9'))
	{
		num = num * 10 + (str[c] - '0');
		c++;
	}
	return (sign * num);
}

// int	main(void)
// {
// 	char num[] = "\t\n\r\v\f  469 \n";
// 	printf("%i\n", ft_atoi(num));
// 	printf("%i\n", atoi(num));
// 	return 0;
// }