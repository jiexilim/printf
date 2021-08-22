#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	outputint(t_fmt *fmt, char *str, int strlen, int nbr)
{
	char	fillwidth;

	fillwidth = ' ';
	if (fmt->zero)
		fillwidth = '0';
	if (!fmt->minus && !fmt->zero)
		fmt->output_len += fill(fmt->width, fillwidth);
	if (nbr < 0)
		fmt->output_len += write(1, "-", 1);
	else if (fmt->plus && nbr >= 0)
		fmt->output_len += write(1, "+", 1);
	else if (fmt->space && nbr >= 0)
		fmt->output_len += write(1, " ", 1);
	if (!fmt->minus && fmt->zero)
		fmt->output_len += fill(fmt->width, fillwidth);
	fmt->output_len += fill(fmt->precision, '0');
	fmt->output_len += write(1, str, strlen);
	if (fmt->minus)
		fmt->output_len += fill(fmt->width, fillwidth);
}

void	print_nbr(t_fmt *fmt)
{
	int		nbr;
	char	*str;
	int		strlen;

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
	if (fmt->dot && !fmt->precision && !nbr)
		strlen = 0;
	if (fmt->precision > strlen)
		fmt->precision = fmt->precision - strlen;
	else
		fmt->precision = 0;
	fmt->width = fmt->width - strlen
		- fmt->precision - (nbr < 0 || fmt->plus || fmt->space);
	outputint(fmt, str, strlen, nbr);
	free(str);
}
