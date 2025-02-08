#include "../push_swap.h"

void sa(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    tmp = (*lst)->next;
    (*lst)->next = tmp->next;
    tmp->next = *lst;
    *lst = tmp;
    write(1, "sa\n", 3);
}