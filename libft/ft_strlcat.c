#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	j = ft_strlen(dst);
	dst_len = j;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && i < (size - 1 - dst_len))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (src_len + dst_len);
}
