#include "push_swap_bonus.h"

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

void operation(t_list **stack_a, t_list **stack_b, char *line)
{
    if (ft_strncmp(line, "rra", 3) == 0)
        rra(stack_a);
    else if (ft_strncmp(line, "rrb", 3) == 0)
        rrb(stack_b);
    else if (ft_strncmp(line, "rrr", 3) == 0)
        rrr(stack_a, stack_b);
    else if (ft_strncmp(line, "rr", 2) == 0)
        rr(stack_a, stack_b);
    else if (ft_strncmp(line, "sa", 2) == 0)
        sa(stack_a);
    else if (ft_strncmp(line, "sb", 2) == 0)
        sb(stack_b);
    else if (ft_strncmp(line, "ss", 2) == 0)
        ss(stack_a, stack_b);
    else if (ft_strncmp(line, "pa", 2) == 0)
        pa(stack_a, stack_b);
    else if (ft_strncmp(line, "pb", 2) == 0)
        pb(stack_a, stack_b);
    else if (ft_strncmp(line, "ra", 2) == 0)
        ra(stack_a);
    else if (ft_strncmp(line, "rb", 2) == 0)
        rb(stack_b);
    else
        exit(1);
}

void check_if_sort(t_list *list)
{
    t_list *tmp;
    tmp = list;

    if (!list || !list->next)
        return ;
    while (tmp->next)
    {
        if (tmp->data > tmp->next->data)
        {
            ft_putstr_fd("KO\n", 1);
            return ;
        }
        tmp = tmp->next;
    }
    ft_putstr_fd("OK\n", 1);
}

int main(int argc, char **argv)
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    int **int_argv;
    char *line = NULL;
    int count;

    count = 0;
    int_argv = get_int_arg(argc, argv, &count);
    stack_a = ft_create_stack(int_argv, count);
    if (!stack_a)
        return (1);
    while (1)
    {
        line = get_next_line(STDIN_FILENO);
        if (!line)
            break ;
        operation(&stack_a, &stack_b, line);
    }
    check_if_sort(stack_a);
    return (0);
}
