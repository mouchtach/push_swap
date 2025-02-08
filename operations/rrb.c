#include "../push_swap.h"

void rrb(t_list **lst)
{
    t_list *tmp;
    t_list *tmp2;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    tmp = *lst;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = *lst;
    *lst = tmp2;
    write(1, "rrb\n", 4);
}