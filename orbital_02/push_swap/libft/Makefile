# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 18:47:47 by frangome          #+#    #+#              #
#    Updated: 2023/05/26 17:59:46 by frangome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_isalpha.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isprint.c\
		ft_strchr.c ft_strlen.c ft_strncmp.c ft_strrchr.c\
		ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memchr.c\
		ft_strlcat.c ft_strlcpy.c ft_strnstr.c ft_atoi.c ft_calloc.c\
		ft_strdup.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c ft_printf.c ft_print_char.c ft_print_pointer.c \
		ft_print_num.c ft_long_itoa.c ft_print_hexa.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(FILES:.c=.o)

BOBJECTS = ${BONUS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(FILES)
	@gcc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(NAME) $(OBJECTS)

re: fclean all

bonus:
	@gcc ${FLAGS} -c ${BONUS}
	@ar rcs ${NAME} ${BOBJECTS}

.PHONY: re all fclean clean