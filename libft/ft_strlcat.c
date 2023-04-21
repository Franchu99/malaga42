/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:21:30 by frangome          #+#    #+#             */
/*   Updated: 2023/04/21 14:28:15 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned long	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	// unsigned int	count;
	// unsigned long	i;
	// unsigned long	j;
	// unsigned long	result;
	// char			*s;

	// s = (char *)src;
	// i = ft_strlen(dest);
	// j = ft_strlen(s);
	// if (size > i)
	// 	result = i + j;
	// else
	// 	result = j + size;
	// count = 0;
	// while (s[count] && (i + 1) < size)
	// {
	// 	dest[i + count] = s[count];
	// 	count++;
	// }
	// dest[i + count] = 0;
	// return (result);
	char	*s;
	unsigned int	len_dst;
	unsigned int	res;
	unsigned int	len_src;
	unsigned int	i;

	s = (char *)src;
	len_dst = ft_strlen(dest);
	len_src = ft_strlen(s);
	res = 0;
	i = 0;
	if (size > len_dst)
		res = len_src + len_dst;
	else
		res = len_src + size;
	while (s[i] && (len_dst + 1) < size)
	{
		dest[len_dst] = s[i];
		len_dst++;
		i++;
	}
	dest[len_dst] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char dest[14] = "a";
// 	ft_strlcat(dest, "lorem ipsum dolor sit amet",15);
// 	printf("%s\n", dest);
// 	return 0;
// }