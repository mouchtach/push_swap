#include "../push_swap.h"


void ft_swap(t_list **list)
{
    t_list *first;
    t_list *triple;

    first = *list;
    triple = (* list)->next->next;
    * list =  (* list)->next;
    (* list)->next = first;
    first->next = triple;
}
void    ft_ss_swap(t_list **list_a,  t_list **list_b)
{
    ft_swap(list_a);
    ft_swap(list_b);
}