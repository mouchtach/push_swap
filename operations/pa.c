#include "../push_swap.h"

void pa(t_list **lst_a, t_list **lst_b)
{
    t_list *tmp;

    if (!lst_b || !*lst_b)
        return ;
    tmp = (*lst_b)->next;
    (*lst_b)->next = *lst_a;
    *lst_a = *lst_b;
    *lst_b = tmp;
    write(1, "pa\n", 3);
}