CC = cc

LIB_CMD = ar -rcs
#ar: create a static library archive:
# -r - create the archive;
# -c - update contents;
# -s - make the archive file.

NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror

SRC =

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):	$(OBJ)
	$(LIB_CMD) $(NAME) $(OBJ)

all:		$(NAME)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
