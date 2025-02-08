
#include "push_swap_bonus.h"

int if_double_sort(int **tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
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

int **atoi_arg(char **str, int **count) 
{
    int i = 0;
    int res = 0;
    int **tab = NULL;

    while (str[**count])
        **count += 1;

    tab = (int **)malloc(sizeof(int *) * (**count + 1));
    if (!tab) 
        return NULL;
    while (i < **count) 
    {
        tab[i] = malloc(sizeof(int));
        if (!tab[i])
            return (ft_free_int(&tab), NULL);
        res = ft_atoi(str[i]);
        if (res == 0 && * str[i] != '0')
            ft_error();
        *tab[i] = res ;
        i++;
    }
    tab[i] = NULL;
    return tab;
}

int check_error(char *str)
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

char *read_arg(int argc, char **argv)
{
    char *str;
    char *tmp;
    int i;

    i = 1;
    tmp = NULL;
    str = NULL;
    if (argc == 1)
        ft_error();
    while(argc > 1)
    {
        if(check_error(argv[i]) == 1)
            ft_error();
        tmp = ft_strdup(str);
        if(str)
            free(str);
        str = ft_strjoin(tmp, argv[i]);
        free (tmp);
        argc--;
        i++;
    }
    return (str);
}
int **get_int_arg(int argc, char **argv, int *count)
{
    char *str;
    char **stack;
    int  **int_stack;

    str = read_arg(argc, argv);
    if (!str)
        return NULL;
    stack = ft_split(str, ' ');
    if (!stack)
        return (ft_free_str(&str), NULL);
    ft_free_str(&str);
    int_stack = atoi_arg(stack, &count);
    if (!int_stack)
        return (ft_free_tab_str(&stack), NULL);
    if (argc != (*count + 1))
    {
        // ft_free_int(&int_stack); //  mochkil fl free
        // ft_free_tab_str(&stack); // mochkil fl free
        ft_error();
    }
    if (if_double_sort(int_stack) == 1)
        ft_error();
    return int_stack;
}