/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:42:10 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/09 18:55:41 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rrb(t_list **lst)
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
