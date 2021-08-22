#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastele;

	if (*lst)
	{
		lastele = ft_lstlast(*lst);
		lastele->next = new;
		return ;
	}
	*lst = new;
}
