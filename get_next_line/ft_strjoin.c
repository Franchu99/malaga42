/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:45:56 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 11:05:33 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length] != 0 && str[length] != '\n')
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size_s1;
	int		size_s2;
	int		c;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = malloc(size_s1 + size_s2 + 1);
	if (!res)
		return (NULL);
	c = 0;
	while (c < size_s1)
	{
		res[c] = s1[c];
		c++;
	}
	c = 0;
	while (c < size_s2 && s2[c] != '\n')
	{
		res[c + size_s1] = s2[c];
		c++;
	}
	res[c + size_s1] = '\0';
	return (res);
}