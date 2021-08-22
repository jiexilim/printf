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
	// TEST(15, print(" %04d ", -14));
	// TEST(16, print(" %05d ", -15));
	// TEST(17, print(" %06d ", -16));
	int i = ft_printf(" %013d ", 4294967295);
	printf("\n");
	int j = printf(" %013d ", 4294967295);
	printf("\n");
	printf("%d\n", i);
	printf("%d\n", j);
	return (0);
}