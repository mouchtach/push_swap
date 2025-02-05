#include "../push_swap.h"

void ft_rotate(t_list **list)
{
    if (!list || !(*list) || !(*list)->next)
        return;

    t_list *first = *list;
    t_list *second = (*list)->next;

    *list = second;
    first->next = NULL;

    t_list *temp = second;
    while (temp->next)
        temp = temp->next;
    temp->next = first;

    write(1, "ra \n", 4);
}

void ft_rr_rotate(t_list **list_a, t_list **list_b)
{
    ft_rotate(list_a);
    ft_rotate(list_b);
    write(1, "rrr \n", 5);
}

void ft_rerotate(t_list **list)
{
    if (!list || !(*list) || !(*list)->next)
        return;

    t_list *first = *list;
    t_list *last = *list;
    t_list *second_last = NULL;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    if (second_last)
        second_last->next = NULL;

    last->next = first;
    *list = last;

    write(1, "rra \n", 5);
}

void ft_rr_rerotate(t_list **list_a, t_list **list_b)
{
    ft_rerotate(list_a);
    ft_rerotate(list_b);
    write(1, "rr \n", 4);
}