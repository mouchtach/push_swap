#include "read.h"

t_list *ft_push_b(t_list *list_a, t_list *list_b)
{
    t_list *tmp;

    tmp = list_a;
    list_a = list_a->next;
    tmp->next = list_b;
    list_b = tmp;
    return (list_b);
}