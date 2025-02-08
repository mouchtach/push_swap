#include "../push_swap_bonus.h"

void ss(t_list **lst_a, t_list **lst_b)
{
    t_list *tmp;

    if (!lst_a || !*lst_a || !(*lst_a)->next)
        return ;
    
    tmp = (*lst_a)->next;
    (*lst_a)->next = tmp->next;
    tmp->next = *lst_a;
    *lst_a = tmp;

    if (!lst_b || !*lst_b || !(*lst_b)->next)
        return ;

    tmp = (*lst_b)->next;
    (*lst_b)->next = tmp->next;
    tmp->next = *lst_b;
    *lst_b = tmp;
}