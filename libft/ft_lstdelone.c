#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*curr;

	curr = lst;
	if (lst->next)
		lst = lst->next;
	del(curr->content);
	free(curr);
}
