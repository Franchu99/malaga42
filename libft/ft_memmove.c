/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:09:37 by frangome          #+#    #+#             */
/*   Updated: 2023/04/23 10:05:19 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, void *src, unsigned int n)
{
	char				*s;
	char				*d;
	unsigned int		c;

	s = (char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (0);
	c = 0;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
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
