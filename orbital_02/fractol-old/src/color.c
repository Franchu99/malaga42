/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:42:24 by frangome          #+#    #+#             */
/*   Updated: 2023/09/11 15:33:13 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

uint32_t	get_dark_palette(int n)
{
	if (n >= 100)
		return (0x000000FF);
	else if (n >= 85)
		return (0xFE7BE5FF);
	else if (n >= 25)
		return (0x974EC3FF);
	else if (n >= 10)
		return (0x504099FF);
	else
		return (0x313866FF);
}

uint32_t	get_bright_palette(int n)
{
	if (n >= 100)
		return (0x000000FF);
	else if (n >= 85)
		return (0xF8DE22FF);
	else if (n >= 25)
		return (0xF94C10FF);
	else if (n >= 10)
		return (0xC70039FF);
	else
		return (0x900C3FFF);
}

uint32_t	get_color(int n, int palette)
{
	if (palette == 0)
		return (get_dark_palette(n));
	else
		return (get_bright_palette(n));
}
