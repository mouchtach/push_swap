/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:27:01 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/11 10:27:03 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "rra"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack_a);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rr"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "sa"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ss"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rb(stack_b);
	else
		return (ft_free_stack(stack_a), 
			ft_free_stack(stack_b), ft_free_str(&line), ft_error());
}

static int	check_if_sort(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (!list || !list->next)
		return (0);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
		return (0);
	aplication_peration(&stack_a, &stack_b);
	if (check_if_sort(stack_a) == 0 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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