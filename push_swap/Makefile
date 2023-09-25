# Target name
NAME = push_swap

# Source and Object files
SRC =	main.c	error.c		stack_init.c		push_swap_utils_1.c		swap.c	\
		push.c	rotate.c	reverse_rotate.c	small_stack.c			big_stack.c \
		quick_sort.c 		push_swap_utils_2.c	push_swap_utils_3.c
OBJ = $(SRC:.c=.o)

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Includes and libraries
INCLUDES = -I./libft/includes
LIBFT = libft/libft.a

# Default target
all:	$(NAME)

# External library dependency
$(LIBFT):
	$(MAKE) -C libft

# Compile object files
$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Main target
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) -lm

# Additional targets
clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
