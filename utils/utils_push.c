/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:00:28 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/09 20:52:40 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index_data(t_list *stack, int value)
{
	t_list	*tmp;
	int		index;

	tmp = stack;
	index = 0;
	while (tmp)
	{
		if (tmp->data == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void	ft_move_node_b_to_top(t_list **stack, int value)
{
	int	target;

	target = find_index_data(*stack, value);
	if (target == 0)
		return ;
	if (target <= ft_lstsize(*stack) / 2)
	{
		while (target > 0)
		{
			rb(stack);
			target--;
		}
	}
	else
	{
		while (target < ft_lstsize(*stack))
		{
			rrb(stack);
			target++;
		}
	}
}

void	ft_move_node_a_to_top(t_list **stack, int value)
{
	int	target;

	target = find_index_data(*stack, value);
	if (target == 0)
		return ;
	if (target <= ft_lstsize(*stack) / 2)
	{
		while (target > 0)
		{
			ra(stack);
			target--;
		}
	}
	else
	{
		while (target < ft_lstsize(*stack))
		{
			rra(stack);
			target++;
		}
	}
}

int	get_min_stack(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = stack->data;
	while (tmp)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max_stack(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = stack->data;
	while (tmp)
	{
		if (max < tmp->data)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}
