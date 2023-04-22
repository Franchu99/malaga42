/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:19:38 by frangome          #+#    #+#             */
/*   Updated: 2023/04/22 18:14:08 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char	*res;

	res = (char *)str;
	while (*res != c)
	{
		if (*res == '\0')
			return (NULL);
		res++;
	}
	return (res);
}
