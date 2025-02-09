/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:43:11 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/09 18:45:35 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_get_index(int **sorted, int data)
{
	size_t	i;

	i = 0;
	while (sorted[i])
	{
		if (*sorted[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

t_list	*ft_create_stack(int **input, int **sorted, int count)
{
	t_list	*stack;
	t_list	*tmp;
	int		index;
	int		i;

	stack = NULL;
	i = 0;
	while (i < count)
	{
		index = ft_get_index(sorted, *input[i]);
		tmp = ft_lstnew(*input[i], index);
		if (!tmp)
			return (ft_lstclear(&stack), NULL);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	ft_free_int(&input);
	ft_free_int(&sorted);
	return (stack);
}
