NAME = libftprintf.a

FILES = ft_printf.c ft_print_char.c ft_print_pointer.c ft_print_num.c\
		ft_long_itoa.c ft_print_hexa.c

OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(FILES)
	@gcc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS)
	@make clean -C libft

fclean:
	@rm -f libft/libft.a
	@rm -f $(NAME) $(OBJECTS)

re: fclean all
	

.PHONY: re all fclean clean