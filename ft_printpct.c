#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	print_pct(t_fmt *fmt)
{
	if (!fmt->minus && fmt->zero)
		fmt->output_len += fill(fmt->width - 1, '0');
	if (!fmt->minus && !fmt->zero)
		fmt->output_len += fill(fmt->width - 1, ' ');
	fmt->output_len += write(1, "%", 1);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width - 1, ' ');
}