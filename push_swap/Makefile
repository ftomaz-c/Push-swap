NAME = push_swap
SRC = main.c error.c stack_init.c swap.c push.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I./libft/includes
LIBFT = libft/libft.a

all:	$(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
