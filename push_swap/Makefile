CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c

$(NAME):
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)

all:		$(NAME)

clean:
	$(MAKE) -C libft clean

fclean:	clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
