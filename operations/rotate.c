#include "../push_swap.h"


void ft_rotate(t_list **list)
{
    t_list *first;
    t_list *secend;

    first = (* list);
    secend = (* list)->next;
    * list = (* list)->next;
    first->next = NULL;
    while (secend->next)
        secend =  secend->next;
    secend->next = first;
}

void    ft_rr_rotate(t_list **list_a, t_list **list_b)
{
    ft_rotate(list_a);
    ft_rotate(list_b);
} 

void ft_rerotate(t_list **list)
{
    t_list  *first;
    t_list  *last;
    
    first = (* list);
    last = (* list);
    while (last->next->next)
        last = last->next;
    (* list) = last->next;
    last->next = NULL;
    (* list)->next = first;
}
void    ft_rr_rerotate(t_list **list_a, t_list **list_b)
{
    ft_rerotate(list_a);
    ft_rerotate(list_b);
}