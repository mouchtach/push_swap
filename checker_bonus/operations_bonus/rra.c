/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:38:18 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/10 13:47:36 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rra(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *lst;
	*lst = tmp2;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rra(stack_b);
}
