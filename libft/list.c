#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return(lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = NULL;
	return(ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if(!lst)
		return(0);
	while(lst)
	{
		lst = lst->next;
		i++;
	}
	return(i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	printlist(t_list *lst)
{
	while(lst)
	{
		ft_putstr_fd(lst->content, 1);
		lst = lst->next;
	}
}

int main()
{
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *d;

	char	s1[] = "qwerty\n";
	char	s2[] = "azerty\n";
	char	s3[] = "HELLo\n";
	char	s4[] = "goodbye\n";

	a = ft_lstnew(s1);
	b = ft_lstnew(s2);
	c = ft_lstnew(s3);
	d = ft_lstnew(s4);
	ft_lstadd_front(&a, b);
	ft_lstadd_front(&a, c);
	printlist(a);
	return(0);
}