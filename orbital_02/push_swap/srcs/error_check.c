/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:08:44 by frangome          #+#    #+#             */
/*   Updated: 2023/08/30 16:34:15 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strstrlen(char **strstr)
{
	int	i;

	i = 0;
	while (strstr[i])
		i++;
	return (i);
}

int	check_args(char *num)
{
	int	i;

	if (num[0] == '\0')
		return (1);
	if (ft_strlen(num) > 10)
		return (1);
	if (ft_atoi(num) > 2147483647 || ft_atoi(num) < -2147483648)
		return (1);
	i = 0;
	while (num[i] != '\0')
	{
		if ((num[i] < 48 || num[i] > 57) && num[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	check_equals(char **argv)
{
	int	i;
	int	j;
	int	len;

	len = strstrlen(argv);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (!ft_strncmp(argv[i], argv[j], 11))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check(char **argv)
{
	int	i;
	int	error;

	error = 0;
	i = 1;
	while (argv[i])
	{
		if (error == 1)
		{
			return (error);
		}
		error = check_args(argv[i]);
		i++;
	}
	if (check_equals(argv))
	{
		error = 1;
	}
	return (error);
}
