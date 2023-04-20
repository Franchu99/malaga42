/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:45:02 by frangome          #+#    #+#             */
/*   Updated: 2023/04/20 15:41:52 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strnstr(char *big, char *little, unsigned int l)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	flag;

	i = 0;
	while (big[i] != 0 && i < l)
	{
		flag = 1;
		j = 0;
		while (little[j] != 0)
		{
			if (big[i + j] != little[j])
				flag = 0;
			j++;
		}
		if (flag && (i + j) <= l)
			return (big + i);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char big[] = "hola buenas";
// 	char little[] = "z";
// 	printf("%s\n", ft_strnstr(big, little, 20));
// 	return 0;
// }