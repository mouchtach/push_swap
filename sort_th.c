#include "push_swap.h"

void    ft_sort_th(t_list **stack_a)
{
    int    a;
    int    b;
    int    c;

    a = (*stack_a)->data;
    b = (*stack_a)->next->data;
    c = (*stack_a)->next->next->data;
    if (a > b && a > c && b > c)
    {
        ft_rotate(stack_a);
        ft_swap(stack_a);
    }
    else if (a > b && a > c && c > b)
        ft_rotate(stack_a);
    else if (a > b && a < c)
        ft_swap(stack_a);
    else if (c < b && c < a && b > a)
        ft_rerotate(stack_a);
    else if (a < b && a < c && b > c)
    {
        ft_rerotate(stack_a);
        ft_swap(stack_a);
    }
    else
        return ;
} 