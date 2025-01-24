#include "push_swap.h"
#include "./libft/libft.h"

int if_double_sort(int **tab)
{
    int i = 0;
    int j = 0;

    while (tab[i])
    {
        j = i + 1;
        while (tab[j])
        {
            if (*tab[i] == *tab[j])
                return (1);
            j++;
        }
        i++;
    }
    i = 0;
    while (tab[i] && tab[i + 1])
    {
        if((*tab[i] > *tab[i + 1]))
            return (0);
        i++;
    }
    return (1);
}

int **intab(char **str, int *count)
{
    int i = 0;
    int res = 0;
    int **tab = NULL;

    while (str[*count])
        *count += 1; 
    tab = (int **)malloc(sizeof(int *) * (*count + 1));
    if (!tab) 
        return NULL;
    while (i < *count) 
    {
        tab[i] = malloc(sizeof(int));
        if (!tab[i])
            return (free_stack_number(&tab), NULL);
        res = ft_atoi(str[i]);
        if(res == 0)
            return (free_stack_number(&tab), NULL);
        *tab[i] = res ;
        i++;
    }
    tab[i] = NULL;
    return tab;
}


int ft_check(char *str)
{
    int i = 0;
    while (str[i])
    {   
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' || str[i] == '+') || (str[i] == ' ')))
            return (1);
        if(i == 0 && (str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
            return (1);
        if(i > 0 && (str[i] == '-' || str[i] == '+'))
        {   
            if(!(str[i + 1] >= '0' && str[i + 1] <= '9') || str[i - 1] != ' ')
            return (1);
        }
        i++;
    }
    return (0);
}
char *input(int c, char **v)
{
    char *str = NULL;
    char *tmp = NULL;
    int i = 1;

    if (c > 1)
    {
        while(c > 1)
        {
            if(ft_check(v[i]) == 1)
            {
                printf("\n\033[1;31mERROR SANTAX\033[0m\n\n");
                exit(0);
            }
            tmp = ft_strdup(str);
            if(str)
                free(str);
            str = ft_strjoin(tmp, v[i]);
            free (tmp);
            c--;
            i++;
        }
    }
    else
    {
        printf("\n\033[1;31mERROR ARGUMENT\033[0m\n\n");
        return (0);
    }
    return (str);
}   




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
int **number_arg(int argc, char **argv)
{
    int count = 0;
    char *strjoin = NULL;
    int **tab = NULL;
    char **str = NULL;

    strjoin = input(argc, argv);
    if(strjoin == NULL)
        return (0);
    str = ft_split(strjoin, ' ');
    tab = intab(str, &count);
    free_stack_string(str);
    free(strjoin);
    if (if_double_sort(tab) == 1)
        return (printf("\n\033[1;31mERROR\033[0m\n\n"), NULL);
    return (tab);
}