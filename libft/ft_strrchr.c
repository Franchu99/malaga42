/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:33:40 by frangome          #+#    #+#             */
/*   Updated: 2023/04/21 21:12:48 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, unsigned int c)
{
	int		count;
	int		match;
	char	*result;

	count = 0;
	match = -1;
	result = (char *)str;
	if ((char)c == 0)
	{
		*result = '\0';
		return (result);
	}
	while (str[count] != 0)
	{
		if (str[count] == (char)c)
			match = count;
		count++;
	}
	if (match < 0)
		return (0);
	result = (char *)str + match;
	return (result);
}
