# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:23:08 by pmessett          #+#    #+#              #
#    Updated: 2023/08/18 17:38:19 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIB_CMD = ar -r -c -s
#ar: create a static library archive:
# -r - create the archive;
# -c - update contents;
# -s - make the archive file.

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src

OBJ_DIR = obj

SRC =	ft_isalpha.c			ft_isdigit.c		ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
		ft_strlen.c				ft_memset.c			ft_bzero.c			ft_memcpy.c			ft_strlcat.c		\
		ft_memmove.c			ft_strlcpy.c		ft_strlcat.c		ft_toupper.c		ft_tolower.c		\
		ft_strchr.c				ft_strrchr.c		ft_strncmp.c		ft_memchr.c			ft_memcmp.c			\
		ft_strnstr.c			ft_atoi.c			ft_calloc.c			ft_strdup.c			ft_substr.c			\
		ft_strjoin.c			ft_strtrim.c		ft_split.c			ft_itoa.c			ft_strmapi.c		\
		ft_striteri.c			ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c		\
		ft_putnbr_base_fd.c		ft_isspace.c		ft_atol.c													\

#ft_printf
SRC +=	ft_printf/ft_printf.c		ft_printf/format_len.c		ft_printf/hex_format.c	ft_printf/nbr_format.c	\
		ft_printf/ptr_format.c		ft_printf/str_format.c		ft_printf/unsg_format.c							\

#get_next_line
SRC +=	get_next_line/get_next_line.c							get_next_line/get_next_line_utils.c				\

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
	$(LIB_CMD) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)

re:	fclean all

.PHONY: all clean fclean re bonus

-include $(OBJ:.o=.d)
