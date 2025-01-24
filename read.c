
#include "push_swap.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>


int ft_double(int **tab)
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
    return (0);
}
int ft_sort(int **tab)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (tab[i] && tab[i + 1])
    {
        if(*tab[i] < *tab[i + 1])
            i++;
        else
            return (0);
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
    while ( i < *count) 
    {
        tab[i] = malloc(sizeof(int));
        res = ft_atoi(str[i]);
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


void ft_print(t_list *list_a, t_list *list_b)
{
    printf("\033[1;32mList A\033[0m\n");
    while (list_a != NULL)
    {
        printf("\033[1;32m%d\033[0m\n", list_a->data);
        list_a = list_a->next;
    }
    printf("\033[1;32mList B\033[0m\n");
    while (list_b != NULL)
    {
        printf("\033[1;32m%d\033[0m\n", list_b->data);
        list_b = list_b->next;
    }

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
int main(int argc, char **argv)
{
    int i = 0;
    t_list *list_a;
    t_list *list_b;
    int count = 0;
    char *strjoin = NULL;
    int **tab = NULL;

    strjoin = input(argc, argv);
    if(strjoin == NULL)
        return (0);
    tab = intab(ft_split(strjoin, ' '), &count);
    free(strjoin);
    printf("count = %d\n", count);
    if (ft_double(tab) == 1)
    {
        printf("\n\033[1;31mERROR DOUBLE\033[0m\n\n");
        return (0);
    }
    if (ft_sort(tab) == 1)
    {
        printf("\n\033[1;32mS O R T E D\033[0m\n\n");
        return (0);
    }
    list_a = ft_list_input(tab, count);
    ft_print_stacks(list_a, list_b);
    ft_push_b(&list_a, &list_b);
    ft_push_b(&list_a, &list_b);
    ft_print_stacks(list_a, list_b);

    



}
