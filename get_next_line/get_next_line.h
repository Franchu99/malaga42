/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:51:26 by frangome          #+#    #+#             */
/*   Updated: 2023/05/03 22:59:48 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int	get_size(char *buffer);
void remove_line(char *buffer, int lsize);
char	*get_next_line(int fd);
#endif