/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:45:02 by frangome          #+#    #+#             */
/*   Updated: 2023/04/24 15:24:35 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, unsigned int l)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	flag;

	if (lit[0] == '\0')
		return ((char *)big);
	if (strlen(lit) > strlen(big))
		return (0);
	i = 0;
	while (big[i] != 0 && i < l)
	{
		flag = 1;
		j = 0;
		while (lit[j] != 0)
		{
			if (big[i + j] != lit[j])
				flag = 0;
			j++;
		}
		if (flag && (i + j) <= l)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char big[] = "hola buenas";
// 	char little[] = "";
// 	printf("%s\n", ft_strnstr(big, little, 0));
// 	printf("%s\n", strnstr(big, little, 0));
// 	return 0;
// }