/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:43:42 by fran              #+#    #+#             */
/*   Updated: 2023/05/01 18:49:29 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_pointer(uintptr_t ptr);
int		get_len(uintptr_t ptr);
void	write_pointer(uintptr_t ptr);
int		ft_print_num(int num);
int		ft_print_unsigned(unsigned int num);
char	*ft_long_itoa(long n);
int		ft_print_hexa(unsigned int num);
int		ft_print_upper_hexa(unsigned int num);

#endif