/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:20:53 by ymouchta          #+#    #+#             */
/*   Updated: 2025/01/22 15:44:52 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (new && lst)
	{
		last = ft_lstlast(*lst);
		last -> next = new;
	}
}
