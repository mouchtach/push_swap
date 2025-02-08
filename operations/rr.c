#include "../push_swap.h"

void rr(t_list **lst_a, t_list **lst_b)
{
    t_list *tmp;
    t_list *tmp2;

    if (!lst_a || !*lst_a || !(*lst_a)->next)
        return ;
    tmp = *lst_a;
    tmp2 = *lst_a;
    *lst_a = (*lst_a)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmp2;
    tmp2->next = NULL;
    if (!lst_b || !*lst_b || !(*lst_b)->next)
        return ;
    tmp = *lst_b;
    tmp2 = *lst_b;
    *lst_b = (*lst_b)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmp2;
    tmp2->next = NULL;
    write(1, "rr\n", 3);
}