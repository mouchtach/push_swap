#include "../push_swap.h"

void ft_push_b(t_list **list_a, t_list **list_b)
{
    t_list *tmp;

    tmp = *list_a;
    *list_a = (* list_a)->next;
    tmp->next = *list_b;
    *list_b = tmp;
}