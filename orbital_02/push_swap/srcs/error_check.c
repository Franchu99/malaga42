/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:08:44 by frangome          #+#    #+#             */
/*   Updated: 2023/05/26 20:09:27 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char *num)
{
	int	i;

	if (ft_atoi(num) > 2147483647 || ft_atoi(num) < -2147483648)
		return (1);
	i = 0;
	while(num[i] != '\0')
	{
		if ((num[i] < 48 || num[i] > 57) && num[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	error_check(char **argv)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (argv[i])
	{
		error = check_args(argv[i]);
		i++;
	}
	return (error);
}