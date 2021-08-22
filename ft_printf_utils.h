#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

void	reset(t_fmt *fmt);
int		fill(int width, char c);
void	print_char(t_fmt *fmt);
void	print_str(t_fmt *fmt);
char	*itoa_base(unsigned long long nbr, char *base);
void	print_ptr(t_fmt *fmt);
void	print_nbr(t_fmt *fmt);
void	print_ui(t_fmt *fmt);
void	print_hex(t_fmt *fmt, char x_type);
void	print_pct(t_fmt *fmt);
void	parse(char **format, t_fmt *fmt);

#endif
