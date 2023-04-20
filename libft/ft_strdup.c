/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:06 by frangome          #+#    #+#             */
/*   Updated: 2023/04/20 17:44:42 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

char	*ft_strdup(const char *s)
{
	int		size;
	int		c;
	char	*str;

	size = 0;
	while (s[size])
		size++;
	str = malloc(size + 1);
	c = 0;
	while (c < size)
	{
		str[c] = s[c];
		c++;
	}
	str[c] = 0;
	return (str);
}

// int	main(void)
// {
// 	char *str = "hola";
// 	printf("%s", ft_strdup(str));
// 	return 0;
// }
