/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:03:18 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/10 14:21:35 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp(line, "rra", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		rrb(stack_a);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(line, "sa", 2) == 0)
		sa(stack_a);
	else if (ft_strncmp(line, "sb", 2) == 0)
		sb(stack_b);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(line, "pa", 2) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(line, "pb", 2) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ra(stack_a);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rb(stack_b);
	else
		return (ft_free_stack(stack_a), 
			ft_free_stack(stack_b), ft_free_str(&line), ft_error());
}

static void	check_if_sort(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (!list || !list->next)
		return ;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
}

static void	aplication_peration(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		operation(stack_a, stack_b, line);
		free(line);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		**int_argv;
	int		count;

	stack_b = NULL;
	stack_a = NULL;
	count = 0;
	int_argv = get_int_arg(argc, argv, &count);
	if (!int_argv)
		return (0);
	stack_a = ft_create_stack(int_argv, count);
	if (!stack_a)
		return (1);
	aplication_peration(&stack_a, &stack_b);
	check_if_sort(stack_a);
	return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), 0);
}

// void	printStack(t_list* stack_a, t_list* stack_b) 
// {
// 	printf("Stack A  |  Stack B\n");
// 	printf("---------------------\n");

// 	while (stack_a || stack_b) {
// 		if (stack_a)
// 			printf("   %d    |", stack_a->data);
// 		else
// 			printf("        |");

// 		if (stack_b)
// 			printf("    %d", stack_b->data);

// 		printf("\n");

// 		if (stack_a) stack_a = stack_a->next;
// 		if (stack_b) stack_b = stack_b->next;
// 	}
// }