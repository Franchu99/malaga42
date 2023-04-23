/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:53 by fran              #+#    #+#             */
/*   Updated: 2023/04/23 22:31:27 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int get_size(char const *s, char c)
{
    int i;
    
    i = 0;
    while (s)
    {
        if (*s != c)
            i++;
        s++;
    }
    return (i);
}

char    **ft_split(char const *s, char c)
{
    char    **res;
    int     i;
    int     j;

    res = malloc(get_size(s, c) + 1);
    if (!res)
        return (0);
    while (!s)
    {
		if (*s == c)
        {
            s++;
			j = 0;
            while (s[j] != c)
            {
				res[i][j] = s[j];
				j++;
			}
			res[i][j] = 0;
			i++;
		}
        
    } 
}