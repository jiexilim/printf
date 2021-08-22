#include "libft.h"

static size_t	arr_size(int n)
{
	size_t	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{	
		size = 1;
		n *= -1;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*arr_app_null(char *arr, int i)
{
	arr[i] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	size_t	size;
	int		i;

	size = arr_size(n);
	arr = malloc(size + 1);
	if (!arr)
		return (NULL);
	if (n == 0)
		arr[0] = '0';
	i = size - 1;
	if (n < 0)
	{
		arr[0] = '-';
		arr[i--] = ((n % 10) * -1) + 48;
		n = (n / 10) * -1;
	}
	while (n > 0)
	{
		arr[i--] = (n % 10) + 48;
		n /= 10;
	}
	return (arr_app_null(arr, size));
}
