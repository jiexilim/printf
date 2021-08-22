#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

static int	is_specifier(char c)
{
	return (c == '-' || c == '0' || c == '.'
		|| c == '#' || c == ' ' || c == '+' || ft_isdigit(c));
}

static void	parse_specifier(char c, t_fmt *fmt)
{
	if (ft_isdigit(c))
	{
		if (fmt->dot)
		{
			fmt->precision = (fmt->precision * 10) + (c - '0');
			fmt->zero = 0;
		}
		else if (c == '0' && !fmt->width && !fmt->minus)
			fmt->zero = 1;
		else
			fmt->width = (fmt->width * 10) + (c - '0');
	}
	else if (c == '-')
		fmt->minus = 1;
	else if (c == '#')
		fmt->hash = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '+')
		fmt->plus = 1;
	else if (c == '.')
		fmt->dot = 1;
}

void	parse(char **format, t_fmt *fmt)
{
	while (*++(*format) && is_specifier(**format))
		parse_specifier(**format, fmt);
	if (!(**format))
		return ;
	else if (**format == 'c')
		print_char(fmt);
	else if (**format == 's')
		print_str(fmt);
	else if (**format == 'p')
		print_ptr(fmt);
	else if (**format == 'd' || **format == 'i')
		print_nbr(fmt);
	else if (**format == 'u')
		print_ui(fmt);
	else if (**format == 'x')
		print_hex(fmt, 'x');
	else if (**format == 'X')
		print_hex(fmt, 'X');
	else if (**format == '%')
		print_pct(fmt);
	(*format)++;
}

void	reset(t_fmt *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->dot = 0;
	fmt->hash = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->width = 0;
	fmt->precision = 0;
}
