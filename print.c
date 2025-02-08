#include "push_swap.h"

void ft_print_int_tab(int **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        printf("%d\n", *tab[i]);
        i++;
    }
}
void ft_print_stack(t_list *lst)
{
    t_list *tmp;

    tmp = lst;
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

void printStacks(t_list* stack_a, t_list* stack_b) 
{
    printf("Stack A  |  Stack B\n");
    printf("---------------------\n");

    while (stack_a || stack_b) {
        if (stack_a)
            printf("   %d    |", stack_a->data);
        else
            printf("        |");

        if (stack_b)
            printf("    %d", stack_b->data);

        printf("\n");

        if (stack_a) stack_a = stack_a->next;
        if (stack_b) stack_b = stack_b->next;
    }
}

void printStacks_index(t_list* stack_a, t_list* stack_b)
{
    printf("Stack A\n");
    printf("Index | Value\n");
    printf("---------------\n");
    while (stack_a) {
        printf("  %zu    |   %d\n", stack_a->index, stack_a->data);
        stack_a = stack_a->next;
    }
    printf("\n");

    printf("Stack B\n");
    printf("Index | Value\n");
    printf("---------------\n");
    while (stack_b) {
        printf("  %zu    |   %d\n", stack_b->index, stack_b->data);
        stack_b = stack_b->next;
    }
    printf("\n");
}