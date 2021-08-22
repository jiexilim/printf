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

// int main()
// {
// 	ft_printf("%5%");
// 	printf("\n");
// 	ft_printf("%-5%");
// 	printf("\n");
// 	ft_printf("%05%");
// 	printf("\n");
// 	ft_printf("%-05%");
// 	printf("\n");

// 	// int i = ft_printf("%-5%");
// 	// printf("\n");
// 	// int j = printf("%-5%");
// 	// printf("\n");
// 	// printf("%d\n", i);
// 	// printf("%d\n", j);
// 	return (0);
// }