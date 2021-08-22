#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	print_ui(t_fmt *fmt)
{
	unsigned int	nbr;
	char			*str;
	int				strlen;
	int				numzeros;
	char			fillwidth;

	nbr = va_arg(fmt->args, unsigned int);
	str = itoa_base(nbr, "0123456789");
	strlen = ft_strlen(str);
	if (fmt->dot && !fmt->precision && !nbr)
		strlen = 0;
	numzeros = 0;
	if (fmt->precision > strlen)
		numzeros = fmt->precision - strlen;
	fillwidth = ' ';
	if (fmt->zero)
		fillwidth = '0';
	if (!fmt->minus)
		fmt->output_len += fill(fmt->width - strlen - numzeros, fillwidth);
	fmt->output_len += fill(numzeros, '0');
	fmt->output_len += write(1, str, strlen);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width - strlen - numzeros, fillwidth);
	free(str);
}
