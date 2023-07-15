/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:22:35 by frangome          #+#    #+#             */
/*   Updated: 2023/07/15 22:29:57 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

typedef struct complex
{
	int	real;
	int	img;
} t_complex;

t_complex *multiply_complex(t_complex *n1, t_complex *n2);
#endif