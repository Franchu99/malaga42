/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:53 by fran              #+#    #+#             */
/*   Updated: 2023/04/24 17:22:02 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
	char	**res;
	int		i;
	int		j;
	int		start;
	int		end;
	int		flag;

	res = malloc((word_counter(s, c) + 1) * sizeof(char *));
	i = 0;
	j = 0;
	start = 0;
	end = 0;
	flag = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && !flag)
		{
			start = i;
			flag = 1;
		}
		if (s[i + 1] == 0 && flag)
		{
			end = i + 1;
			res[j] = insert_word(s, start, end);
			j++;
		}
		if (s[i] == c && flag && s[i + 1] != 0)
		{
			end = i;
			flag = 0;
			res[j] = insert_word(s, start, end);
			j++;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
