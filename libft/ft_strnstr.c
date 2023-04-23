/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:45:02 by frangome          #+#    #+#             */
/*   Updated: 2023/04/23 12:04:34 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strnstr(const char *big, const char *lit, unsigned int l)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	flag;

	if (!lit && l == 0)
		return ((char *)big);
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
	return (0);
}

// int	main(void)
// {
// 	char big[] = "hola buenas";
// 	char little[] = "";
// 	printf("%s\n", ft_strnstr(big, little, 0));
// 	printf("%s\n", strnstr(big, little, 0));
// 	return 0;
// }