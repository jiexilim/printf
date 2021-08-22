#include "libft/libft.h"
#include "ft_printf.h"

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

int	is_specifier(char c)
{
	return (c == '-' || c == '0' || c == '.'
		|| c == '#' || c == ' ' || c == '+' || ft_isdigit(c));
}

void	parse_specifier(char c, t_fmt *fmt)
{
	if (ft_isdigit(c))
	{
		if (fmt->dot)
			fmt->precision = (fmt->precision * 10) + (c - '0');
		else if (c == '0' && !fmt->width)
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

int	fill(int width, char c)
{
	int	count;

	count = 0;
	while (width-- > 0)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

void	print_char(t_fmt *fmt)
{
	int c;

	c = va_arg(fmt->args, int);
	if (fmt->minus)
		fmt->output_len += write(1, &c, 1);
	fmt->output_len += fill(fmt->width - 1, ' ');
	if (!fmt->minus)
		fmt->output_len += write(1, &c, 1);

}

void	print_str(t_fmt *fmt)
{
	char *str;
	int	strlen;
	int	numspaces;
	
	str = va_arg(fmt->args, char *);
	if (!str)
	{
		str = "(null)";
		if (fmt->precision < 6)
			fmt->precision = 0;
	}
	strlen = ft_strlen(str);
	if (fmt->precision > strlen || !fmt->dot)
		numspaces = strlen;
	else
		numspaces = fmt->precision;
	if (!fmt->minus)
		fmt->output_len += fill(fmt->width - numspaces, ' ');
	fmt->output_len += write(1, str, numspaces);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width - numspaces, ' ');
}


static size_t	arr_size(unsigned long nbr, unsigned long radix)
{
	size_t	size;

	size = 1;
	while (nbr > (radix - 1))
	{
		nbr /= radix;
		size++;
	}
	return (size);
}

char	*itoa_base(unsigned long long nbr, char *base)
{
	int		radix;
	char	*arr_base;
	size_t	size;
	radix = ft_strlen(base);
	size = arr_size(nbr, radix);
	arr_base = malloc(size + 1);
	if (!arr_base)
		return (NULL);
	arr_base[size--] = '\0';
	if (nbr == 0)
		arr_base[size] = '0';
	while (nbr > 0)
	{
		arr_base[size] = base[nbr % radix];
		nbr /= radix;
		size--;
	}
	return (arr_base);
}

void	print_ptr(t_fmt *fmt)
{
	char	*str;
	char	*ptr;
	int		ptrlen;

	str = va_arg(fmt->args, char *);
	// if (!str)
	// {
	// 	fmt->output_len += write(1, "(nil)", 5);
	// 	return ;
	// }
	ptr = itoa_base((unsigned long) str, "0123456789abcdef");
	ptrlen = ft_strlen(ptr);
	if (fmt->width > ptrlen && !fmt->minus)
		fmt->output_len += fill(fmt->width - ptrlen - 2, ' ');
	fmt->output_len += (write(1, "0x", 2) + write(1, ptr, ptrlen));
	if (fmt->width > ptrlen && fmt->minus)
		fmt->output_len += fill(fmt->width - ptrlen - 2, ' ');
	free(ptr);
}

void	print_nbr(t_fmt *fmt)
{
	int		nbr, strlen, numzeros;
	char	*str;
	char	fillwidth;

	nbr = va_arg(fmt->args, int);
	if (nbr < -2147483648 || nbr > 2147483647)
		nbr = 0;
	if (nbr == -2147483648)
		str = itoa_base((long) nbr * -1, "0123456789");
	else if (nbr < 0)
		str = ft_itoa(-nbr);
	else
		str = ft_itoa(nbr);
	strlen = ft_strlen(str);
	numzeros = 0;
	if (fmt->precision > strlen)
		numzeros = fmt->precision - strlen;
	else if (fmt->zero && fmt->width > strlen)
		numzeros = fmt->width - strlen - (fmt->plus || nbr < 0);
	fillwidth = ' ';
	if (!fmt->dot && fmt->zero)
		fillwidth = '0';
	if (!fmt->minus)
		fmt->output_len += fill(fmt->width - strlen - numzeros - (nbr < 0 || fmt->plus), fillwidth);
	if (nbr < 0)
		fmt->output_len += write(1, "-", 1);
	if (fmt->plus && nbr >= 0)
		fmt->output_len += write(1, "+", 1);
	else if (fmt->space && nbr >= 0)
		fmt->output_len += write(1, " ", 1);
	fmt->output_len += fill(numzeros, '0');
	fmt->output_len += write(1, str, strlen);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width - strlen - numzeros - (nbr < 0 || fmt->plus || fmt->space), fillwidth);
	free(str);
}

void	print_ui(t_fmt *fmt)
{
	unsigned int		nbr;
	int		strlen, numzeros;
	char	*str;
	char	fillwidth;

	nbr = va_arg(fmt->args, unsigned int);
	str = itoa_base(nbr, "0123456789");
	strlen = ft_strlen(str);
	numzeros = 0;
	if (fmt->precision > strlen)
		numzeros = fmt->precision - strlen;
	fillwidth = ' ';
	if (!fmt->dot && fmt->zero)
		fillwidth = '0';
	if (!fmt->minus)
		fmt->output_len += fill(fmt->width - strlen - numzeros , fillwidth);
	fmt->output_len += fill(numzeros, '0');
	fmt->output_len += write(1, str, strlen);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width - strlen - numzeros , fillwidth);
	free(str);
}

void print_hex(t_fmt *fmt, char x_type)
{
	unsigned int	nbr;
	char			*hex_arr;
	int		arrlen, numzeros;
	char	fillwidth;

	nbr = va_arg(fmt->args, unsigned int);
	if (x_type == 'X')
		hex_arr = itoa_base((unsigned long) nbr, "0123456789ABCDEF");
	else
		hex_arr = itoa_base((unsigned long) nbr, "0123456789abcdef");
	arrlen = ft_strlen(hex_arr);
	numzeros = 0;
	if (fmt->precision > arrlen)
		numzeros = fmt->precision - arrlen;
	fillwidth = ' ';
	if (!fmt->dot && fmt->zero)
		fillwidth = '0';
	if (!fmt->minus)
		fmt->output_len += fill(fmt->width - arrlen - numzeros - (fmt->hash * 2), fillwidth);
	if (fmt->hash && nbr)
		fmt->output_len += write(1, "0", 1) + write(1, &x_type, 1);
	fmt->output_len += fill(numzeros, '0');
	fmt->output_len += write(1, hex_arr, arrlen);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width - arrlen - numzeros - (fmt->hash * 2), fillwidth);
	free(hex_arr);
}

void	print_hash(t_fmt *fmt)
{
	if (!fmt->minus && fmt->zero)
		fmt->output_len += fill(fmt->width - 1, '0');
	if (!fmt->minus && !fmt->zero)
		fmt->output_len += fill(fmt->width - 1, ' ');
	fmt->output_len += write(1, "%", 1);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width - 1, ' ');
}

void	parse(char **format, t_fmt *fmt)
{
	while (*++(*format) && is_specifier(**format))
		parse_specifier(**format, fmt);
	if (**format == 'c')
		print_char(fmt);
	if (**format == 's')
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
		print_hex(fmt,'X');
	else if (**format == '%')
		print_hash(fmt);
	return ;
}

