#include "libft/libft.h"
#include "ft_printf.h"


int		ft_printf(const char *format, ...)
{
	t_fmt	*fmt;
	int		output_len;
	
	fmt = malloc(sizeof(t_fmt));
	va_start(fmt->args, format);
	fmt->output_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			reset(fmt);
			parse((char **) &format, fmt);
			format++;
			continue;
		}
		fmt->output_len += write(1, format++, 1);
	}
	va_end(fmt->args);
	output_len = fmt->output_len;
	free(fmt);
	return (output_len);
}

int main()
{
	// " %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42
	int i = ft_printf(" %d ", -2147483648);
	// int i = ft_printf("%s", "haha");
	printf("\n");
	int j = printf(" %d ",-2147483648);
	printf("\n");
	printf("%d\n", i);
	printf("%d\n", j);
	return (0);
}