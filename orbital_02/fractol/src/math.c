/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:10:46 by frangome          #+#    #+#             */
/*   Updated: 2023/07/15 22:33:59 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex *multiply_complex(t_complex *n1, t_complex *n2)
{
	t_complex *sol;
	
	sol->real = (n1->real * n2->real) - (n1->img * n2->img);
	sol->img = (n1->real + n2->real) * n2->img;

	return (sol);
}
