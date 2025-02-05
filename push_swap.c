
#include "push_swap.h"
#include "libft/libft.h"

// void finsh_target(t_list **list_a, t_list **list_b, int index)
// {
//     t_list *a;
//     int i;
//     i = 0;

//     a = *list_a; 
//     if(index == 0)
//     {
//         ft_push_a(list_a, list_b);
//         return;
//     }
//     if(index < (ft_lstsize(*list_a) / 2))
//     {
//         while (i < index)
//         {
//             ft_rotate(list_a);
//             i++;
//         }
//     }
//     else
//     {
//         i = (ft_lstsize(*list_a) - index) + 1;
//         while (i--)
//         {
//             ft_rerotate(list_a);
//         }
//     }
//     ft_push_a(list_a, list_b);
// }
int ft_min(t_list *list)
{
    t_list *tmp;
    int min;
    int i = 0;

    tmp = list;
    min = list->data;
    while (list)
    {
        if (list->data < min)
            min = list->data;
        list = list->next;
    }
    while (tmp)
    {
        if (tmp->data == min)
            break;
        tmp = tmp->next;
        i++;
    }
    return i;
}


void sort_list(t_list **list, int min)
{
    if(min == 0)
        return;
    else if(min < (ft_lstsize(*list) / 2))
    {
        while(min--)
            ft_rotate(list);
    }
    else
    {
        min = (ft_lstsize(*list) - min);
        while(min--)
            ft_rerotate(list);
    }
}
int find_tar(t_list *list, int data)
{
    int target = -1;
    int i = 0, index = 0;
    t_list *tmp = list;

    while (list)
    {
        if ((list->data > data && target == -1) || 
            (list->data > data && list->data < target))
        {
            target = list->data;
            index = i;
        }
        i++;
        list = list->next;
    }

    if (target == -1) // No larger element found, return smallest index
    {
        target = tmp->data;
        index = 0;
        i = 0;
        while (tmp)
        {
            if (tmp->data < target)
            {
                target = tmp->data;
                index = i;
            }
            i++;
            tmp = tmp->next;
        }
    }
    return index;
}

// int find_tar(t_list *list, int data)
// {
//     int target;
//     int i;
//     i = 0;
//     t_list *tmp;
//     target = 0;
//     tmp = list;
//     while(list)
//     {
//         if (list->data > data && target == 0)
//             target = list->data;
//         else if (list->data > data && list->data < target && target != 0)
//             target = list->data;
//         list = list->next;
//     }
//     while (tmp)
//     {
//         if (tmp->data == target)
//             break;
//         i++;
//         tmp = tmp->next;
//     }
//     return i;
// }
void finsh_target(t_list **list_a, t_list **list_b, int index)
{
    int size = ft_lstsize(*list_a);
    int i = 0;

    if (index == 0)
    {
        ft_push_a(list_a, list_b);
        return;
    }

    if (index < size / 2)
    {
        while (i < index)
        {
            ft_rotate(list_a);
            i++;
        }
    }
    else
    {
        i = size - index;  // Fix off-by-one error
        while (i--)
        {
            ft_rerotate(list_a);
        }
    }
    ft_push_a(list_a, list_b);
}
void    ft_target(t_list **list_a, t_list **list_b)
{

    t_list *b;
    int content;
    int index;

    b = *list_b;


    while (b)
    {
        content = b->data;
        index = find_tar(*list_a, content);
        // printf("content = %d\n", content);
        // printf("target = %d\n", index);
        finsh_target(list_a, list_b, index);
        b = *list_b;
    }
}

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
void ft_separation_range(t_list **list_a, t_list **list_b, int count)
{
    int range = ft_range(*list_a, count);
    int i = 0;
    t_list *tmp = *list_a;

    while (tmp && ft_lstsize(*list_a) > 3)
    {
        if (tmp->data < range)
        {
            if (i < ft_lstsize(*list_a) / 2)
            {
                while (i--)
                    ft_rotate(list_a);
            }
            else
            {
                i = ft_lstsize(*list_a) - i;
                while (i--)
                    ft_rerotate(list_a);
            }
            ft_push_b(list_a, list_b);
            tmp = *list_a;
            i = 0;  // Reset counter
        }
        else
        {
            tmp = tmp->next;
            i++;
        }
    }
}

// void  ft_separation_range(t_list **list_a, t_list **list_b, int count)
// {
//     t_list *tmp;
//     int i;
//     int range;

//     i = 1;
//     tmp = *list_a;


//     range = ft_range(*list_a, count);
//     printf("range = %d\n", range);
//     printf("size/2 = %d\n", (ft_lstsize(*list_a) / 2));
    
//     while (tmp)
//     {
//         if ((tmp->data) < range && ft_lstsize(*list_a) > 3)
//         {
//             if (i == 1 || i < (ft_lstsize(*list_a) / 2))
//             {
//                 while (--i)
//                     ft_rotate(list_a);
//                 ft_push_b(list_a, list_b);
//                 tmp = *list_a;
//             }
//             else
//             {
//                 i = (ft_lstsize(*list_a) - i) + 1;
//                 while (i--)
//                     ft_rerotate(list_a);
//                 ft_push_b(list_a, list_b);
//                 i = 0;
//                 tmp = *list_a;
//             }
//         }
//         else 
//             tmp = tmp->next;
//         i++;
//     }
    
// }


int push_swap(t_list **list_a, t_list **list_b, int count)
{

    ft_separation_range(list_a, list_b, count);
    
    while (ft_lstsize(*list_a) > 3)
    {
        ft_push_b(list_a, list_b);
    }

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
    ft_sort_th(&list_a);
    ft_target(&list_a, &list_b);
    // printf("min = %d\n", ft_min(list_a));
    sort_list(&list_a, ft_min(list_a));
    // ft_print_stacks(list_a, list_b);
    close(fd);
    return 0;
}
