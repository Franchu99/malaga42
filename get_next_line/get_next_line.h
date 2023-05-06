/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:18:27 by fran              #+#    #+#             */
/*   Updated: 2023/05/06 12:06:21 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

# define GETNEXTLINE_H
#include <stdlib.h>
#include <unistd.h>


char            *get_next_line(int fd);
int             put_line(char *buffer);
void	        remove_line(char *buffer);
char	        *ft_strjoin(char const *s1, char const *s2);
void	        fill_line(char *line, char *buffer);
int	            is_line(char *buffer);
unsigned int	ft_strlen(const char *str);

#endif