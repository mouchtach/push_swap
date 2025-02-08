#include "../push_swap_bonus.h"

void rrr(t_list **lst_a, t_list **lst_b)
{
    t_list *tmp;
    t_list *tmp2;


    if (!lst_a || !*lst_a || !(*lst_a)->next)
        return ;
    tmp = *lst_a;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = *lst_a;
    *lst_a = tmp2;

    if (!lst_b || !*lst_b || !(*lst_b)->next)
        return ;
    tmp = *lst_b;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = *lst_b;
    *lst_b = tmp2;
}