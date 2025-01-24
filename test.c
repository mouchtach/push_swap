#include <stdio.h>
#include <stdlib.h>


typedef struct s_list
{
	int			data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
        new->prev = NULL;  
		return ;
	}
	if (new && lst)
	{
		last = ft_lstlast(*lst);
		last -> next = new;
	}
}
t_list	*ft_lstnew(int content, t_list **prev)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->data = content;
    element->prev = *prev;
	element->next = NULL;
	return (element);
}
int main() {

    t_list *head = NULL;
    t_list *tmp;
    t_list *tmmp;
    t_list *pp;
    
    
    int i = 7;
    tmp = head;
    tmmp = head;
    pp = head;
    while (i--)
    {
        tmp = ft_lstnew(i, &tmmp);
        ft_lstadd_back(&head, tmp);
        tmmp = tmp;
    }
    while (head)
    {
        if(head->prev != NULL)
            printf("data dyal li 9bal %p\n", head->prev);
        printf("data dyali%d\n", head->data);
        head = head->next;
    }
    printf("data  null = %p\n", head->next);
        
    
    
    // // tmmp = tmmp->next;
    // while ( tmmp->prev != NULL && tmmp)
    // {
    //     printf("data dyal li 9bal %d\n", tmmp->prev->data);
    //     tmmp = tmmp->next;
    // }
}

