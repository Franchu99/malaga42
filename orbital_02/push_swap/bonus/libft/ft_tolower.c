/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:53:25 by frangome          #+#    #+#             */
/*   Updated: 2023/04/23 10:13:34 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int upper)
{
	if (upper >= 65 && upper <= 90)
		return (upper + 32);
	else
		return (upper);
}
