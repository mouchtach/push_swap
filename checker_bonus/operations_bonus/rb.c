#include "../push_swap_bonus.h"

void rb(t_list **lst)
{
    t_list *tmp;
    t_list *tmp2;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    tmp = *lst;
    tmp2 = *lst;
    *lst = (*lst)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmp2;
    tmp2->next = NULL;
}