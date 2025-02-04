
#include "push_swap.h"
#include "libft/libft.h"

int ft_range(t_list *list, int count)
{
    float range = 0;
    while (list)
    {
        range += list->data;
        list = list->next;
    }
    return ((int)(range / count));
}
void  ft_separation_range(t_list **list_a, t_list **list_b, int count)
{
    t_list *tmp;
    int i;
    int range;

    i = 1;
    tmp = *list_a;


    range = ft_range(*list_a, count);
    printf("range = %d\n", range);
    printf("size/2 = %d\n", (ft_lstsize(*list_a) / 2));
    
    while (tmp)
    {
        if ((tmp->data) < range)
        {
            if (i == 1 || i < (ft_lstsize(*list_a) / 2))
            {
                while (--i)
                    ft_rotate(list_a);
                ft_push_b(list_a, list_b);
                tmp = *list_a;
            }
            else
            {
                i = (ft_lstsize(*list_a) - i) + 1;
                while (i--)
                    ft_rerotate(list_a);
                ft_push_b(list_a, list_b);
                i = 0;
                tmp = *list_a;
            }
        }
        else 
            tmp = tmp->next;
        i++;
    }
    
}


int push_swap(t_list **list_a, t_list **list_b, int count)
{

    ft_separation_range(list_a, list_b, count);
    
    // while (ft_lstsize(*list_a) > 3)
    // {
    //     ft_push_b(list_a, list_b);
    // }

    return 0;
}

int main(int argc, char **argv)
{
    t_list *list_a = NULL;
    t_list *list_b = NULL;
    int count;
    int **tab = NULL;
    count = 0;
    int fd = open("operations.txt", O_CREAT | O_RDWR, 0777);
    tab = number_arg(argc, argv, &count);
    if (tab == NULL)
        return (0);
    list_a = ft_list_input(tab, count);
    push_swap(&list_a, &list_b, count);
    ft_print_stacks(list_a, list_b);
    close(fd);
    return 0;
}
