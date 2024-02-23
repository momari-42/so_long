CFLALGS 	= 	-Wall -Wextra -Werror
NAME 		= 	so_long
NAME_BONUS 	= 	so_long_bonus
CC 			= 	cc
SRCLIB		= 	libft/libft.a
SRCPRI 		= 	ft_printf/libftprintf.a

SRC 		= 	mandatory/so_long.c 	   \
				mandatory/so_long_utils1.c \
				mandatory/so_long_utils2.c \
				mandatory/so_long_utils3.c \
				mandatory/so_long_utils4.c \
				mandatory/so_long_utils5.c

BSRC 		= 	bonus/so_long_bonus.c			\
				bonus/so_long_utils1_bonus.c	\
				bonus/so_long_utils2_bonus.c	\
				bonus/so_long_utils3_bonus.c	\
				bonus/so_long_utils4_bonus.c	\
				bonus/so_long_utils5_bonus.c	\
				bonus/so_long_utils6_bonus.c

 
OBJS 	= 	$(SRC:.c=.o)
BOBJS 	= 	$(BSRC:.c=.o)

MYLB	=	libft
MYHD	=	libft/libft.a

PRLB	=	ft_printf
PRHD	=	ft_printf/libftprintf.a

all	 : $(MYLB) $(PRLB) $(NAME)

bonus: $(MYLB) $(PRLB) $(NAME_BONUS)

$(MYLB):
	make -C $(MYLB)

$(PRLB):
	make -C $(PRLB)

%_bonus.o: %_bonus.c $(MYHD) $(PRHD) bonus/so_long_bonus.h
	$(CC) $(CFLALGS) -c -I $(MYLB) -I $(PRLB) $< -o $@

%.o: %.c $(MYHD) $(PRHD) mandatory/so_long.h
	$(CC) $(CFLALGS) -c -I $(MYLB) -I $(PRLB) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLALGS) $(OBJS) -L $(MYLB) -lft -L $(PRLB) -lftprintf -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS) : $(BOBJS)
	$(CC) $(CFLALGS) $(BOBJS) -L $(MYLB) -lft -L $(PRLB) -lftprintf -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) 

clean:
	cd libft && make clean
	cd ft_printf && make clean
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	cd libft && make fclean
	cd ft_printf && make fclean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: $(MYLB) $(PRLB)