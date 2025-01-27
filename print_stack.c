#include "push_swap.h"


void    ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
    printf("\033[1;35m===========\033[0m\n");
    printf("\033[1;35mstack_a\033[0m\n");
    if (!stack_a)
        printf("\033[1;35mEMPTY!\033[0m\n");
    while (stack_a)
    {
        
        printf("\033[1;35m---\033[0m\n");
        printf("\033[1;31m| %d |\033[0m\n", stack_a->data);
        printf("\033[1;35m --- \033[0m\n");
        stack_a = stack_a->next;
    }
    printf("\033[1;35m===========\033[0m\n");
    printf("\033[1;35mstack_b\033[0m\n");
    if (!stack_b)
        printf("\033[1;35mEMPTY!\033[0m\n");
    while (stack_b)
    {
        
        printf("\033[1;35m---\033[0m\n");
        printf("\033[1;31m| %d |\033[0m\n", stack_b->data);
        printf("\033[1;35m --- \033[0m\n");
        stack_b = stack_b->next;
    }
}