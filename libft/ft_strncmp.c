#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	if (n == 0)
		return (0);
	i = 0;
	s1_ptr = (unsigned char *) s1;
	s2_ptr = (unsigned char *) s2;
	while (i < n && s1_ptr[i] && s2_ptr[i])
	{
		if (s1_ptr[i] != s2_ptr[i])
			break ;
		i++;
	}
	if (i < n)
		return (s1_ptr[i] - s2_ptr[i]);
	return (0);
}
