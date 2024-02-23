NAME	= libftprintf.a
SRC		= ft_printf.c  ft_putchar.c ft_putstr.c ft_putnbr_h.c \
			ft_putnbr_a.c ft_putnbr.c ft_putnbr_u.c
OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Werror
CC		= cc

all: $(NAME)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY : all clean fclean re