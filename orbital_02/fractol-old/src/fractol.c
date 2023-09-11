/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:21:33 by frangome          #+#    #+#             */
/*   Updated: 2023/09/11 18:56:51 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	param_t	*tmp;

	tmp = param;
	if (keydata.action == 0)
	{
		if (keydata.key == 334)
			tmp->zoom = tmp->zoom * 0.9;
		else if (keydata.key == 333)
			tmp->zoom = tmp->zoom * 1.1;
		else if (keydata.key == 262)
			tmp->x_origin += 0.1 * tmp->zoom;
		else if (keydata.key == 263)
			tmp->x_origin -= 0.1 * tmp->zoom;
		else if (keydata.key == 264)
			tmp->y_origin += 0.1 * tmp->zoom;
		else if (keydata.key == 265)
			tmp->y_origin -= 0.1 * tmp->zoom;
		else if (keydata.key == 256)
			mlx_close_window(tmp->mlx);
		print_set(tmp->img, tmp);
	}
}

void	scroll_func(double xdelta, double ydelta, void *param)
{
	param_t	*tmp;

	tmp = param;
	xdelta = 0;
	if (ydelta > 0)
	{
		tmp->zoom = tmp->zoom * 1.1;
		tmp->x_origin += tmp->x_mouse;
		tmp->y_origin += tmp->y_mouse;
	}
	else if (ydelta < 0)
	{
		tmp->zoom = tmp->zoom * 0.9;
		tmp->x_origin += tmp->x_mouse;
		tmp->y_origin += tmp->y_mouse;
	}
	print_set(tmp->img, tmp);
}

void	mouse_pos(double xpos, double ypos, void *param)
{
	param_t	*tmp;

	tmp = param;
	tmp->x_mouse = (xpos - (WIDTH / 2.0)) * (4.0 / WIDTH) * tmp->zoom;
	tmp->y_mouse = (ypos - (HEIGHT / 2.0)) * (4.0 / HEIGHT) * tmp->zoom;
	// if (tmp->change_or)
	// {
	// 	tmp->c_real = xpos - (WIDTH / 2.0) * (4.0 / WIDTH);
	// 	tmp->c_img = -(ypos - (HEIGHT / 2.0) * (4.0 / HEIGHT));
	// 	print_set(tmp->img, tmp);
	// }
}

void	print_param(void)
{
	ft_printf("You need to write 3 parameters:\n set: 0 Mandelbrot 1 Julia\n");
	ft_printf("color: 0 Cold 1 Calid\n");
	ft_printf("coor set 0: -1.34228188 0\n");
	ft_printf("coor set 1: -0.7 0.27015\n");
	ft_printf("coor set 2: 0.32998906 0.050599865\n");
}

int	check_coor(char **argv, param_t *param)
{
	if (ft_atoi(argv[3]) == 0)
	{
		param->c_real = -1.34228188;
		param->c_img = 0;
		return (1);
	}
	else if (ft_atoi(argv[3]) == 1)
	{
		param->c_real = -0.7;
		param->c_img = 0.27015;
		return (1);
	}
	else if (ft_atoi(argv[3]) == 2)
	{
		param->c_real = 0.32998906;
		param->c_img = 0.050599865;
		return (1);
	}
	else
		return (0);
}

int	check_set(char **argv, param_t *param)
{
	int res;
	
	res = 0;
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) == 1)
	{
		param->set = ft_atoi(argv[1]);
		res = 1;
	}
	else
		return (0);
	if (ft_atoi(argv[2]) == 0 || ft_atoi(argv[2]) == 1)
	{
		param->color = ft_atoi(argv[2]);
		res = 1;
	}
	else
		return (0);
	return (res);
}

int32_t	main(int argc, char **argv)
{
	param_t		param;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 4)
		return (print_param(), 0);
	param.zoom = 1;
	param.x_origin = 0;
	param.y_origin = 0;
	if (!check_coor(argv, &param) || !check_set(argv, &param))
		return (print_param(), 0);
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	param.mlx = mlx;
	param.img = img;
	print_set(img, &param);
	mlx_cursor_hook(mlx, mouse_pos, &param);
	mlx_scroll_hook(mlx, scroll_func, &param);
	mlx_key_hook(mlx, key_hook, &param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
