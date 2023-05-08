/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:18:27 by fran              #+#    #+#             */
/*   Updated: 2023/05/08 20:25:07 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 75
# endif

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
int				nline(char *buffer);
void			remove_line(char *buffer);
char			*ft_strjoin(char const *s1, char const *s2);
void			fill_line(char *line, char *buffer);
int				is_line(char *buffer);
unsigned int	ft_strlen(const char *str);
char			*no_line(char *line, char *buffer, int fd, int i);
void			empty_buffer(char *buffer);

#endif