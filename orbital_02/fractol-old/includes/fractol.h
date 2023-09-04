/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:21:36 by frangome          #+#    #+#             */
/*   Updated: 2023/09/04 18:30:44 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 1000 // Ancho de la imagen
#define HEIGHT 1000 // Alto de la imagen
#define MAX_ITER 100 // Máximo número de iteraciones

typedef struct param
{
	double			zoom;
	mlx_image_t*	img;
	mlx_t* 			mlx;
	
} param_t;

void	print_set(mlx_image_t	*img, param_t *param);
int		mandelbrot(int x, int y, param_t *param);
int		julia(double x, double y, double c_real, double c_img, param_t *param);

uint32_t	get_color(int	n);

#endif