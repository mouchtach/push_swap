#include "../push_swap_bonus.h"

t_list *ft_create_stack(int **input, int count)
{
    t_list *stack;
    t_list *tmp;
    t_list  *f;
    int i;

    i = 0;
    stack = ft_lstnew(*input[i]);
    f = stack;
    while (++i < count)
    {    
        tmp = malloc(sizeof(t_list));
        if (!tmp)
            return (ft_free_stack(&stack), NULL); // mochkil fl free
        if ((int)index == -1)
            return (ft_free_stack(&stack), NULL); // mochkil fl free
        tmp->data = *input[i];
        tmp->next = NULL;
        f->next = tmp;
        f = tmp;
    }
    return (stack);
}

