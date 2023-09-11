/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:20:52 by frangome          #+#    #+#             */
/*   Updated: 2023/09/11 17:24:18 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_set(mlx_image_t	*img, param_t *param)
{
	int	i;
	int	j;

	i = 1;
	while (i < WIDTH)
	{
		j = 1;
		while (j < HEIGHT)
		{
			if (param->set == 0)
				mlx_put_pixel(img, i, j, get_color(mandelbrot(i, j, param), param->color));
			else if (param->set == 1)
				mlx_put_pixel(img, i, j, get_color(julia(i, j, param), param->color));
			j++;
		}
		i++;
	}
}

int	mandelbrot(int x, int y, param_t *param)
{
	double			real;
	double			im;
	mandelbrot_t	mandel;

	real = (((x - WIDTH / 2.0) * 4.0 / WIDTH) * param->zoom) + param->x_origin;
	im = (((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * param->zoom) + param->y_origin;
	mandel.zx = 0;
	mandel.zy = 0;
	mandel.iteration = 0;
	while (mandel.iteration < MAX_ITER)
	{	
		mandel.zx2 = mandel.zx * mandel.zx;
		mandel.zy2 = mandel.zy * mandel.zy;
		if (mandel.zx2 + mandel.zy2 > 4.0)
			return (mandel.iteration);
		mandel.zy = 2 * mandel.zx * mandel.zy + im;
		mandel.zx = mandel.zx2 - mandel.zy2 + real;
		mandel.iteration++;
	}
	return (MAX_ITER);
}

int	julia(double x, double y, param_t *param)
{
	double	zx;
	double	zy;
	int		iteration;
	double	zx2;
	double	zy2;

	zx = (((x - WIDTH / 2.0) * 4.0 / WIDTH) * param->zoom) + param->x_origin;
	zy = (((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * param->zoom) + param->y_origin;
	iteration = 0;
	while (iteration < MAX_ITER)
	{
		zx2 = zx * zx;
		zy2 = zy * zy;
		if (zx2 + zy2 > 4.0)
			return (iteration);
		zy = 2 * zx * zy + param->c_img;
		zx = zx2 - zy2 + param->c_real;
		iteration++;
	}
	return (MAX_ITER);
}
