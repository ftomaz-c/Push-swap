CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c	error.c		stack_init.c	swap.c	push.c \
INCLUDES = -I./libft/includes

all:	$(NAME)

$(NAME):
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C libft clean

fclean:	clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
