#include "../push_swap.h"

t_list *ft_list_input(int **input, int count)
{
    int i = 0;
    t_list *new;
    t_list *list_a = NULL;

    while (i < count)
    {
        new = ft_lstnew(*input[i]);
        if (!new)
        {
            ft_lstclear(&list_a);
            return (NULL);
        }
        ft_lstadd_back(&list_a, new);
        i++;
    }
    return(list_a);
}

