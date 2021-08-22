SRCS = ./ft_printf.c ./ft_printf_utils.c ./ft_printchar.c \
	./ft_printhex.c ./ft_printnbr.c ./ft_printpct.c \
	./ft_printptr.c ./ft_printstr.c ./ft_printtype_utils.c \
	./ft_printui.c

OBJS = $(SRCS:c=o)

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_OBJS = libft/*.o

all : $(NAME)

$(NAME) : $(OBJS) makelibft
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

makelibft :
	make -C libft/

# %.c : %.o
# 	gcc $(CFLAGS) -I $(INCLUDE) -c $< -o ${<:c=o}

bonus : $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) libft/libft.a

re : fclean all