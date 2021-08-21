SRCS = ./ft_printf_utils.c ./ft_printf.c

OBJS = $(SRCS:c=o)

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_OBJS = $(libft/)*.o

all : $(NAME)

$(NAME) : $(OBJS) makelibft
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

makelibft :
	cd libft; make re; cd ..;

# %.c : %.o
# 	gcc $(CFLAGS) -I $(INCLUDE) -c $< -o ${<:c=o}

bonus : $(NAME)

clean:
	cd libft; make clean; cd ..;
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) libft/libft.a

re : fclean all