/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:18:27 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 19:05:19 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 75
#endif

# define GETNEXTLINE_H
#include <stdlib.h>
#include <unistd.h>


char            *get_next_line(int fd);
int             nline(char *buffer);
void	        remove_line(char *buffer);
char	        *ft_strjoin(char const *s1, char const *s2);
void	        fill_line(char *line, char *buffer);
int	            is_line(char *buffer);
unsigned int	ft_strlen(const char *str);

#endif