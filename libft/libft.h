/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:52:24 by frangome          #+#    #+#             */
/*   Updated: 2023/04/23 10:54:53 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int digit);
int				ft_isprint(int c);
void			*ft_memset(void *str, int c, unsigned int n);
char			*ft_strchr(const char *str, char c);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strrchr(const char *str, int c);
int				ft_tolower(int upper);
int				ft_toupper(int lower);
void			ft_bzero(void *s, unsigned int n);
void			*ft_memchr(const void *s, int c, unsigned int n);
unsigned long	ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned long	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strnstr(const char *big, const char *lit, unsigned int l);
int				ft_atoi(const char *str);
void			*ft_calloc(unsigned int nmemb, unsigned int size);
char			*ft_strdup(const char *s);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
void			*ft_memmove(void *dest, void *src, unsigned int n);
#endif