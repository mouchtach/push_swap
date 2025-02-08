/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:46:15 by ymouchta          #+#    #+#             */
/*   Updated: 2024/10/25 11:51:13 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			x;
	long long	t;

	i = 0;
	x = 1;
	t = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -x;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		t = (t * 10) + (str[i] - 48);
		if ((t * x) > INT_MAX ||(t * x) < INT_MIN)
			return (0);
		i++;
	}
	return ((int)(t * x));
}
