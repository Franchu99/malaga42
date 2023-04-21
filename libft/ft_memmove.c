/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:09:37 by frangome          #+#    #+#             */
/*   Updated: 2023/04/21 12:16:53 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, void *src, unsigned int n)
{
	char				*s;
	char				*d;
	unsigned int		c;

	s = (char *)src;
	d = (char *)dest;
	c = 0;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
    else
	{
		while (c < n)
		{
			d[c] = s[c];
			c++;
		}
	}
	return (dest);
}
