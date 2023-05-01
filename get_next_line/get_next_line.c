/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:06:42 by fran              #+#    #+#             */
/*   Updated: 2023/05/02 00:30:32 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*realloc_buffer(char *buffer, char *nbuffer, int bsize, int bread)
{
	int i;
	
	bsize *= 2;
	nbuffer = malloc(bsize);
	i = 0;
	while (i < bread)
	{
		nbuffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (nbuffer);
}

char	*get_next_line(int fd)
{
	char    *buffer;
	char	*nbuffer;
	char	c;
	int		bsize;
	int		bread;

	bsize = 1;
	buffer = malloc(bsize);
	while (read(fd, &c, 1) > 0)
	{
		buffer[bread] = c;
		bead++;
		if (bread == bsize)
			buffer = realloc_buffer(buffer, nbuffer, bsize, bread);
	}    
}
/*
implementar ft_realloc para este proyecto.
crear un archivo txt para testear antes de complicar mas el codigo.
*/