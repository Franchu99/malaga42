/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:20:52 by frangome          #+#    #+#             */
/*   Updated: 2023/09/04 18:32:50 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..//includes/fractol.h"

void print_set (mlx_image_t	*img, param_t *param)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < WIDTH)
	{
		j = 1;
		while (j < HEIGHT)
		{
			mlx_put_pixel(img, i, j, get_color(julia(i, j, -0.7, 0.27015, param)));
			j++;
		}
		i++;
	}
}

int mandelbrot(int x, int y, param_t *param)
{
    double real = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * param->zoom;
    double imag = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * param->zoom;
    double zx = 0;
    double zy = 0;
    int iteration = 0;

    while (iteration < MAX_ITER) {
        double zx2 = zx * zx;
        double zy2 = zy * zy;
        if (zx2 + zy2 > 4.0)
            return iteration;
        zy = 2 * zx * zy + imag;
        zx = zx2 - zy2 + real;
        iteration++;
    }

    return MAX_ITER;
}

int julia(double x, double y, double c_real, double c_img, param_t *param)
{
    double	zx = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * param->zoom;
    double	zy = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * param->zoom;
    int		iteration = 0;

    while (iteration < MAX_ITER) {
        double zx2 = zx * zx;
        double zy2 = zy * zy;
        if (zx2 + zy2 > 4.0) {
            return iteration;
        }
        zy = 2 * zx * zy + c_img;
        zx = zx2 - zy2 + c_real;
        iteration++;
    }

    return MAX_ITER;
}
