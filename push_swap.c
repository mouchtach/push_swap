
#include "push_swap.h"
#include "libft/libft.h"

int ft_position(t_list *list)
{
    

}

float ft_range(t_list *list, int count)
{
    float range;
    while (list)
    {
        range += list->data;
        list = list->next;
    }
    return(range / count);
}

int push_swap(t_list **list_a, t_list **list_b, int count)
{
    t_list *tmp;
    int i;
    int len;
    float range;

    i = 1;
    tmp = * list_a;

    // hna f range = total volume / len
    range = ft_range(* list_a, count);
    printf("range = %f\n", range);
    printf("size/2 = %d\n", (ft_lstsize(* list_a) / 2));
    
    // o hna  pushit --> list_b  ga3 ar9am li sghar mn range 
    while (tmp)
    {
        
        if(i == 1 && (tmp->data) <= range)
        {
            ft_push_b(list_a,list_b);
            i = 0;
            tmp = * list_a;
        }
        else if(i >= 1 && (tmp->data) <= range)
        {
            if(i < (ft_lstsize(* list_a) / 2))
            {
                while (--i)
                    ft_rotate(list_a);
                ft_push_b(list_a, list_b);
                i = 0;
                tmp = * list_a;
            }
            else if(i > (ft_lstsize(* list_a) / 2))
            {
                i = (ft_lstsize(* list_a) - i) + 1;
                while (i--)
                    ft_rerotate(list_a);
                ft_push_b(list_a, list_b);
                i = 0;
                tmp = * list_a;
            }
        }
        else 
            tmp = tmp->next;
        i++;
    }
    // hna pushit--> b ga3 dakchi li b9a Lia f list a o khalit 3
    tmp = list_a; 
    while(tmp->next->next->next)
    {
        ft_push_b(&list_a, &list_b);
        tmp = list_a;
    }
}

int main(int argc, char **argv)
{
    t_list *list_a = NULL;
    t_list *list_b = NULL;
    int count;
    int **tab = NULL;
    count = 0;
    int fd = open("operations.txt", O_CREAT | O_RDWR, 777);
    tab = number_arg(argc, argv, &count);
    if(tab == NULL)
        return (0);
    list_a = ft_list_input(tab, count);
    push_swap(&list_a, &list_b, count);
    ft_print_stacks(list_a, list_b);
       
}
