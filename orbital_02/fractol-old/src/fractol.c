/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:21:33 by frangome          #+#    #+#             */
/*   Updated: 2023/09/04 18:28:51 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void key_hook(mlx_key_data_t keydata, void* param)
{
	param_t *tmp = param;
	if (keydata.action == 0)
	{
		if (keydata.key == 334)
		{
			tmp->zoom = tmp->zoom * 0.9;
			print_set(tmp->img, tmp);
		}
		else if (keydata.key == 333)
		{
			tmp->zoom = tmp->zoom * 1.1;
			print_set(tmp->img, tmp);
		}
		else if (keydata.key == 256)
			mlx_terminate(tmp->mlx);
	}
}

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	mlx = NULL;
}

int32_t	main(void)
{
	param_t	param;

	param.zoom = 1;
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	param.mlx = mlx;
	param.img = img;
	print_set(img, &param);
	
	mlx_key_hook(mlx, key_hook, &param);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}