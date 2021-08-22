#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

#endif