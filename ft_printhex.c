#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	outputhex(t_fmt *fmt, char *hex_arr, int arrlen, char x_type)
{
	char	fillwidth;

	fillwidth = ' ';
	if (fmt->zero)
		fillwidth = '0';
	if (!fmt->minus)
		fmt->output_len += fill(fmt->width, fillwidth);
	if (fmt->hash && hex_arr[0] != '0')
		fmt->output_len += write(1, "0", 1) + write(1, &x_type, 1);
	fmt->output_len += fill(fmt->precision, '0');
	fmt->output_len += write(1, hex_arr, arrlen);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width, fillwidth);
}

void	print_hex(t_fmt *fmt, char x_type)
{
	unsigned int	nbr;
	char			*hex_arr;
	int				arrlen;

	nbr = va_arg(fmt->args, unsigned int);
	if (x_type == 'X')
		hex_arr = itoa_base((unsigned long) nbr, "0123456789ABCDEF");
	else
		hex_arr = itoa_base((unsigned long) nbr, "0123456789abcdef");
	arrlen = ft_strlen(hex_arr);
	if (fmt->dot && !fmt->precision && !nbr)
		arrlen = 0;
	if (fmt->precision > arrlen)
		fmt->precision = fmt->precision - arrlen;
	else
		fmt->precision = 0;
	fmt->width = fmt->width - arrlen - fmt->precision - (fmt->hash * 2);
	outputhex(fmt, hex_arr, arrlen, x_type);
	free(hex_arr);
}
