#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	print_ptr(t_fmt *fmt)
{
	char	*str;
	char	*ptr;
	int		ptrlen;
	int		numzeros;

	str = va_arg(fmt->args, char *);
	ptr = itoa_base((unsigned long) str, "0123456789abcdef");
	ptrlen = ft_strlen(ptr);
	if (fmt->dot && !fmt->precision && !str)
		ptrlen = 0;
	numzeros = 0;
	if (fmt->precision > ptrlen)
		numzeros = fmt->precision - ptrlen;
	if (fmt->width > ptrlen && !fmt->minus)
		fmt->output_len += fill(fmt->width - ptrlen - numzeros - 2, ' ');
	fmt->output_len += (write(1, "0x", 2));
	fmt->output_len += fill(numzeros, '0');
	fmt->output_len += write(1, ptr, ptrlen);
	if (fmt->width > ptrlen && fmt->minus)
		fmt->output_len += fill(fmt->width - ptrlen - numzeros - 2, ' ');
	free(ptr);
}
