/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:00:02 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/10 16:49:59 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		**int_argv;
	int		**int_sorted;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	count = 0;
	int_argv = get_int_arg(argc, argv, &count);
	if (!int_argv)
		return (0);
	int_sorted = ft_sort_int_tab(int_argv, count);
	if (!int_argv || !int_sorted)
		return (ft_free_int(&int_argv), ft_free_int(&int_sorted), 1); 
	stack_a = ft_create_stack(int_argv, int_sorted, count);
	if (!stack_a)
		return (ft_free_int(&int_argv), ft_free_int(&int_sorted), 1); 
	if (count <= 5)
		ft_sort_if_tive(&stack_a, &stack_b, count);
	else
	{
		ft_push_if(&stack_a, &stack_b, count);
		finish_sort(&stack_a, &stack_b);
	}
	return(0);
}
