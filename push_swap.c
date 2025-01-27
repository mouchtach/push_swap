
#include "push_swap.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
    t_list *list_a = NULL;
    t_list *list_b = NULL;
    int count;
    int **tab = NULL;
    count = 0;
    tab = number_arg(argc, argv, &count);
    if(tab == NULL)
        return (0);
    
    printf("count :%d \n", count);
    list_a = ft_list_input(tab, count);
    ft_push_b(&list_a, &list_b);
    ft_push_b(&list_a, &list_b);
    ft_push_b(&list_a, &list_b);
    ft_rr_rerotate(&list_a, &list_b);
    ft_push_a(&list_a, &list_b);
    ft_push_a(&list_a, &list_b);
    ft_push_a(&list_a, &list_b);   
    ft_print_stacks(list_a, list_b);      
}
