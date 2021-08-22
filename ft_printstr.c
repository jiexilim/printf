#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	print_str(t_fmt *fmt)
{
	char	*str;
	int		strlen;
	int		numspaces;

	str = va_arg(fmt->args, char *);
	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (fmt->precision > strlen || !fmt->dot)
		numspaces = strlen;
	else
		numspaces = fmt->precision;
	fmt->width = fmt->width - numspaces;
	if (!fmt->minus && !fmt->zero)
		fmt->output_len += fill(fmt->width, ' ');
	if (!fmt->minus && fmt->zero)
		fmt->output_len += fill(fmt->width, '0');
	fmt->output_len += write(1, str, numspaces);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width, ' ');
}
