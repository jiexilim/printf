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
// 	int i = ft_printf("%.i", 0);
//        printf("a\n");
//        int y = ft_printf("%5.0i", 0);
//        printf("a\n");
//        ft_printf("%5.i", 0);
//       printf("a\n");
//       ft_printf("%-5.0i", 0);
//       printf("a\n");
// 	  printf("%d\n", i);
// 	  printf("%d\n", y);
// 	return (0);
// }