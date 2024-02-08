# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momari <momari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 15:08:39 by momari            #+#    #+#              #
#    Updated: 2024/02/04 22:37:17 by momari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLALGS = -Wall -Wextra -Werror
NAME = so_long
CC = cc
SRC = 	mandatory/src/get_next_line.c mandatory/src/get_next_line_utils.c \
		mandatory/src/ft_putchar_fd.c mandatory/src/ft_putendl_fd.c  \
		mandatory/src/ft_putstr_fd.c \
		mandatory/src/ft_lstadd_back.c \
		mandatory/src/ft_lstclear.c \
		mandatory/src/ft_lstlast.c \
		mandatory/src/ft_lstnew.c \
		mandatory/src/ft_lstsize.c \
		mandatory/src/ft_memset.c \
	 	mandatory/so_long_utils_1.c \
	 	mandatory/so_long_utils_2.c so_long.c

#BSRC =

OBJS = $(SRC:.c=.o)
#BOBJS = $(BSRC:.c=.o)

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLALGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLALGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address

# bonus: $(BOBJS)
# 	ar rcs $(NAME) $(BOBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(BOBJS)

re: fclean all