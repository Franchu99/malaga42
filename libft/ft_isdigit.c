/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:41:18 by frangome          #+#    #+#             */
/*   Updated: 2023/04/19 15:48:59 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}
