/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:33:40 by frangome          #+#    #+#             */
/*   Updated: 2023/04/19 15:49:39 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
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
