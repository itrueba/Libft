#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;    
    t_list	*new;

	start = NULL;
	if (!lst || !f)
		return (0);
	while (lst)
	{
        new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**start;    
    t_list	*new;

	start = NULL;
	if (!lst || !f)
		return (0);
	while (lst)
	{
        new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(*start, del);
			return (0);
		}
		ft_lstadd_back(*start, new);
		lst = lst->next;
	}
	return (*start);
}
