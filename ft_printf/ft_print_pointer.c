/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:11:32 by fran              #+#    #+#             */
/*   Updated: 2023/04/30 15:10:17 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_len(uintptr_t ptr)
{
    int len;
    
    len = 0;
    while (ptr > 0)
    {
        len++;
        ptr /= 10;
    }
    return (len);
}

void write_pointer(uintptr_t ptr)
{
    if (ptr >= 16)
    {
        write_pointer(ptr / 16);
        write_pointer(ptr % 16);
    }
    else
    {
    if (ptr <= 9)
        ft_print_char(ptr + '0');
    else
        ft_print_char(ptr - 10 + 'a'); 
    }
}

int ft_print_pointer(uintptr_t ptr)
{
    int len;

    len = 2;
    write(1, "0x", 2);
    if (ptr == 0)
        len += write(1, "0", 1);
    else
    {
        write_pointer(ptr);
        len += get_len(ptr);
        
    }
    return (len);
}