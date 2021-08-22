#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

static size_t	arr_size(unsigned long nbr, unsigned long radix)
{
	size_t	size;

	size = 1;
	while (nbr > (radix - 1))
	{
		nbr /= radix;
		size++;
	}
	return (size);
}

char	*itoa_base(unsigned long long nbr, char *base)
{
	int		radix;
	size_t	size;
	char	*arr_base;

	radix = ft_strlen(base);
	size = arr_size(nbr, radix);
	arr_base = malloc(size + 1);
	if (!arr_base)
		return (NULL);
	arr_base[size--] = '\0';
	if (nbr == 0)
		arr_base[size] = '0';
	while (nbr > 0)
	{
		arr_base[size] = base[nbr % radix];
		nbr /= radix;
		size--;
	}
	return (arr_base);
}

int	fill(int width, char c)
{
	int	count;

	count = 0;
	while (width-- > 0)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}
