/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:53 by fran              #+#    #+#             */
/*   Updated: 2023/04/26 17:41:10 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(char const *s, char c)
{
	int		i;
	int		flag;
	int		n;

	i = 0;
	flag = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && !flag)
		{
			n++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
	i++;
	}
	return (n);
}

char	*insert_word(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	word = malloc(finish - start + 1);
	i = 0;
	while (start < finish)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char				**res;
	unsigned int		i;
	unsigned int		j;
	int					flag;

	res = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (0);
	i = 0;
	j = 0;
	flag = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0 && i != (unsigned int)ft_strlen(s))
			flag = i;
		if ((s[i] == c || i == ft_strlen(s)) && flag >= 0)
		{
			res[j++] = insert_word(s, flag, i);
			flag = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
