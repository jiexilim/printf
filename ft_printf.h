#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define FD_STDOUT 1

typedef struct	s_fmt
{
	va_list	args;
	int		output_len;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
}	t_fmt;

int		ft_printf(const char *format, ...);
void	reset(t_fmt *fmt);
void	parse(char **format, t_fmt *fmt);

#endif