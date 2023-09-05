# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:23:08 by pmessett          #+#    #+#              #
#    Updated: 2023/09/05 16:37:11 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	src/ft_isalpha.c		src/ft_isdigit.c	src/ft_isalnum.c	src/ft_isascii.c	src/ft_isprint.c		\
		src/ft_strlen.c			src/ft_memset.c		src/ft_bzero.c		src/ft_memcpy.c		src/ft_strlcat.c		\
		src/ft_memmove.c		src/ft_strlcpy.c	src/ft_strlcat.c	src/ft_toupper.c	src/ft_tolower.c		\
		src/ft_strchr.c			src/ft_strrchr.c	src/ft_strncmp.c	src/ft_memchr.c		src/ft_memcmp.c			\
		src/ft_strnstr.c		src/ft_atoi.c		src/ft_calloc.c		src/ft_strdup.c		src/ft_substr.c			\
		src/ft_strjoin.c		src/ft_strtrim.c	src/ft_split.c		src/ft_itoa.c		src/ft_strmapi.c		\
		src/ft_striteri.c		src/ft_putchar_fd.c	src/ft_putstr_fd.c	src/ft_putendl_fd.c	src/ft_putnbr_fd.c		\
		src/ft_putnbr_base_fd.c	src/ft_isspace.c	src/ft_atol.c

#ft_printf
SRC +=	src/ft_printf/ft_printf.c	src/ft_printf/format_len.c	src/ft_printf/hex_format.c	src/ft_printf/nbr_format.c	\
		src/ft_printf/ptr_format.c	src/ft_printf/str_format.c	src/ft_printf/unsg_format.c

#get_next_line
SRC +=	src/get_next_line/get_next_line.c	src/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
INCLUDES = -I./includes
LIB_CMD = ar -r -c -s
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
REMOVE = rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
	$(LIB_CMD) $(NAME) $(OBJ)

clean:
	$(REMOVE) $(OBJ)

fclean:	clean
	$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
