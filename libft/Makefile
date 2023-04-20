# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 18:47:47 by frangome          #+#    #+#              #
#    Updated: 2023/04/20 18:05:20 by frangome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_strchr.c ft_strlen.c ft_strncmp.c ft_strrchr.c\
		ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memchr.c\
		ft_strlcat.c ft_strlcpy.c ft_strnstr.c ft_atoi.c ft_calloc.c\
		ft_strdup.c ft_memcpy.c

OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(FILES)
	gcc $(FLAGS) -c $(FILES)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all

.PHONY: re all fclean clean