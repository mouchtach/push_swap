#include "../push_swap_bonus.h"

void sa(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    tmp = (*lst)->next;
    (*lst)->next = tmp->next;
    tmp->next = *lst;
    *lst = tmp;
}