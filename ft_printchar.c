#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	print_char(t_fmt *fmt)
{
	int	c;

	c = va_arg(fmt->args, int);
	if (fmt->minus)
		fmt->output_len += write(1, &c, 1);
	fmt->output_len += fill(fmt->width - 1, ' ');
	if (!fmt->minus)
		fmt->output_len += write(1, &c, 1);
}
