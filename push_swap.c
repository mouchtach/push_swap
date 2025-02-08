/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:00:02 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/08 23:46:23 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void finish_sort(t_list **stack_a, t_list **stack_b)
{
    int max;
    int count;

    count = ft_lstsize(*stack_b);
    while (count > 0)
    {
        max = get_max_stack(*stack_b);
        ft_move_node_b_to_top(stack_b, max);
        pa(stack_a, stack_b);
        count--;
    }
    ft_free_stack(stack_b);
    ft_free_stack(stack_a);
}

void ft_push_if_range(t_list **stack_a, t_list **stack_b, int big, int count)
{
    int small;

    small = 0;
    while (count-- > 0)
    {
        if ((*stack_a)->index >= small && (*stack_a)->index <= big)
        {
            pb(stack_a, stack_b);
            small++;
            big++;
        }
        else if ((*stack_a)->index > big)
        {
            ra(stack_a);
            count++;
        }
        else
        {
            pb(stack_a, stack_b);
            rb(stack_b);
            small++;
            big++;
        }
    }
}
void ft_push_if(t_list **stack_a, t_list **stack_b, int count)
{
    if (count <= 100)
        ft_push_if_range(stack_a, stack_b, 15, count);
    else 
        ft_push_if_range(stack_a, stack_b, 30, count);
}

void ft_sort(int **tab, int count)
{
    int i, j, tmp;

    if (!tab)
        return;

    i = 0;
    while (i < count)
    {
        j = i + 1;
        while (j < count)
        {
            if (*tab[i] > *tab[j])
            {
                tmp = *tab[i];
                *tab[i] = *tab[j];
                *tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
    tab[i] = NULL;
}

int **ft_sort_int_tab(int **tab, int **sort_int, int count)
{
    int i;
    int j;
    int tmp;

    i = 0;
    sort_int = (int **)malloc(sizeof(int *) * (count + 1));
    if (!sort_int)
        return (ft_free_int(&sort_int),ft_free_int(&tab), NULL);
    while (i < count)
    {
        sort_int[i] = malloc(sizeof(int));
        if (!sort_int[i])
            return (ft_free_int(&sort_int),ft_free_int(&tab), NULL);
        *sort_int[i] = *tab[i];
        i++;
    }
    ft_sort(sort_int, count);
    return (sort_int);
}


int main(int argc, char **argv)
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    int **int_argv;
    int **int_sorted;
    int count;

    count = 0;
    int_argv = get_int_arg(argc, argv, &count);
    if (!int_argv)
        return (1);
    int_sorted = ft_sort_int_tab(int_argv, int_sorted, count);
    if (!int_argv || !int_sorted)
        return (ft_free_int(&int_argv), ft_free_int(&int_sorted), 1); 
    stack_a = ft_create_stack(int_argv, int_sorted, count);
    if (!stack_a)
        return (ft_free_int(&int_argv), ft_free_int(&int_sorted), 1); 
    if (count <= 5)
        ft_sort_5(&stack_a, &stack_b, count);
    else
    {
        ft_push_if(&stack_a, &stack_b, count);
        finish_sort(&stack_a, &stack_b);
    }
}
