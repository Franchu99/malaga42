/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:51:26 by frangome          #+#    #+#             */
/*   Updated: 2023/05/03 16:59:31 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int	get_size(char *buffer);
void remove_line(char *buffer, int lsize);
char	*get_next_line(int fd);
#endif