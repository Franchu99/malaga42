/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:21:30 by frangome          #+#    #+#             */
/*   Updated: 2023/04/22 18:13:02 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned long	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	char			*s;
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