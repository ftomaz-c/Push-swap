CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c	error.c		stack_init.c

LIBFT = libft/libft.a

$(NAME):
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)


all:		$(NAME)

clean:
	$(MAKE) -C libft clean

fclean:	clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
