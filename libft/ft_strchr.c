/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:19:38 by frangome          #+#    #+#             */
/*   Updated: 2023/04/19 15:49:13 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, char c)
{
	int	count;

	count = 0;
	while (str[count] != c)
	{
		if (str[count] == 0)
			return (0);
		count++;
	}
	return (str + count);
}
