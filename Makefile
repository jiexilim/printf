SRCS = ./ft_printf.c ./ft_printf_utils.c ./ft_printchar.c \
	./ft_printhex.c ./ft_printnbr.c ./ft_printpct.c \
	./ft_printptr.c ./ft_printstr.c ./ft_printtype_utils.c \
	./ft_printui.c

OBJS = $(SRCS:c=o)

LIBFT_DIR = libft/

LIBFT_OBJS = $(LIBFT_DIR)*.o

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) makelibft
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

makelibft :
	make -C $(LIBFT_DIR)

bonus : $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(LIBFT_DIR)libft.a

re : fclean all

.PHONY: all clean fclean re
