/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:45:02 by frangome          #+#    #+#             */
/*   Updated: 2023/04/25 20:30:57 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, unsigned int l)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	flag;

	if (lit[0] == '\0')
		return ((char *)big);
	if (ft_strlen(lit) > ft_strlen(big))
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
