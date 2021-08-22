#include "libft.h"

static size_t	wrd_cnt(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
			continue ;
		}
		str++;
	}
	return (count);
}

static void	split(char **s, char c, char ***arr, int *arr_i)
{
	size_t	start;
	size_t	end;
	int		i;

	start = 0;
	while ((*s)[start])
	{
		while ((*s)[start] && (*s)[start] == c)
			start++;
		if (start >= ft_strlen(*s))
			return ;
		end = start;
		while ((*s)[end] && (*s)[end] != c)
			end++;
		(*arr)[*arr_i] = malloc(end - start + 1);
		i = 0;
		while (start < end)
			(*arr)[*arr_i][i++] = (*s)[start++];
		(*arr)[(*arr_i)++][i] = '\0';
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_i;

	if (!s)
		return (NULL);
	arr = (char **) malloc(sizeof(char *) * wrd_cnt((char *) s, c) + 1);
	if (!arr)
		return (NULL);
	arr_i = 0;
	split((char **) &s, c, &arr, &arr_i);
	arr[arr_i] = NULL;
	return (arr);
}
