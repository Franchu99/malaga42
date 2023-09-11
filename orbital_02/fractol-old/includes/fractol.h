/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:21:36 by frangome          #+#    #+#             */
/*   Updated: 2023/09/11 18:19:58 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 1000 // Ancho de la imagen
#define HEIGHT 1000 // Alto de la imagen
#define MAX_ITER 100// Máximo número de iteraciones

typedef struct param
{
	double			zoom;
	double			x_origin;
	double			y_origin;
	double			x_mouse;
	double			y_mouse;
	double			c_real;
	double			c_img;
	int				set;
	int				color;
	// int				change_or;
	mlx_image_t*	img;
	mlx_t* 			mlx;
	
} param_t;

typedef	struct mandelbrot
{
	double	zx;
	double	zy;
	int 	iteration;
	double	zx2;
	double	zy2;

} mandelbrot_t;

void		print_set(mlx_image_t	*img, param_t *param);
int			mandelbrot(int x, int y, param_t *param);
int			julia(double x, double y, param_t *param);
uint32_t	get_color(int	n, int palette);

#endif