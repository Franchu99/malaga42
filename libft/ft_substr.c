/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:37:22 by fran              #+#    #+#             */
/*   Updated: 2023/04/23 12:53:07 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if ((size_t)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	result = malloc(len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, (char *)(s + start), len + 1);
	return (result);
}
