/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:05:22 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/10 12:41:54 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_tow(t_list **lst)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	if ((*lst)->data > (*lst)->next->data)
		sa(lst);
}

void	ft_sort_three(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->data;
	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if (a > b && a > c && b > c)
	{
		ra(lst);
		sa(lst);
	}
	else if (a > b && a > c && c > b)
		ra(lst);
	else if (a > b && a < c)
		sa(lst);
	else if (c < b && c < a && b > a)
		rra(lst);
	else if (a < b && a < c && b > c)
	{
		rra(lst);
		sa(lst);
	}
	else
		return ;
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min_stack(*stack_a);
	ft_move_node_a_to_top(stack_a, min);
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min_stack(*stack_a);
	ft_move_node_a_to_top(stack_a, min);
	pb(stack_a, stack_b);
	min = get_min_stack(*stack_a);
	ft_move_node_a_to_top(stack_a, min);
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_sort_if_tive(t_list **lst_a, t_list **lst_b, int count)
{
	if (count == 2)
		ft_sort_tow(lst_a);
	else if (count == 3)
		ft_sort_three(lst_a);
	else if (count == 4)
		ft_sort_four(lst_a, lst_b);
	else if (count == 5)
		ft_sort_five(lst_a, lst_b);
	ft_free_stack(lst_b);
	ft_free_stack(lst_a);
}
