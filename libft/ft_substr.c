#include "libft.h"

static char	*arr_app_null(char *arr, int i)
{
	arr[i] = '\0';
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newsub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		newsub = malloc(1);
		return (arr_app_null(newsub, 0));
	}
	else if (len > s_len)
	{
		len = s_len;
		newsub = malloc(len - start + 1);
	}
	else
		newsub = malloc(len + 1);
	if (!newsub)
		return (newsub);
	i = 0;
	while (s[start] && i < len)
		newsub[i++] = s[start++];
	return (arr_app_null(newsub, i));
}
