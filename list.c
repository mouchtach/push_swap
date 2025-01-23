#include "read.h"

t_list *ft_list_input(int **input, int count)
{
    int i = 0;
    t_list *list_a = NULL;

    while (i < count)
    {
        ft_lstadd_back(&list_a, ft_lstnew(*input[i]));
        i++;
    }

    return(list_a);
}

