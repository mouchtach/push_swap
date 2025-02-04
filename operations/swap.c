#include "../push_swap.h"

void ft_swap(t_list **list)
{
    t_list *first;
    t_list *second;
    t_list *third;

    if (!list || !(*list) || !((*list)->next))
        return;

    first = *list;
    second = (*list)->next;
    third = second->next;

    *list = second;
    second->next = first;
    first->next = third;
}

void ft_ss_swap(t_list **list_a, t_list **list_b)
{
    ft_swap(list_a);
    ft_swap(list_b);
}