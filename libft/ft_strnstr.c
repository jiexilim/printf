#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	i;
	size_t	needle_len;

	if (!*needle)
		return ((char *) haystack);
	i = 0;
	needle_len = ft_strlen(needle);
	while (haystack[i] && i < size)
	{
		if (haystack[i] == needle[0]
			&& !ft_strncmp(&haystack[i], needle, needle_len)
			&& i + needle_len <= size)
			return ((char *) &haystack[i]);
		i++;
	}
	return (NULL);
}
