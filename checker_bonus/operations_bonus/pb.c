/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:33:46 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/09 18:55:32 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_a || !*lst_a)
		return ;
	tmp = (*lst_a)->next;
	(*lst_a)->next = *lst_b;
	*lst_b = *lst_a;
	*lst_a = tmp;
}
