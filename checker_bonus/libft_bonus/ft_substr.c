/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:19:49 by ymouchta          #+#    #+#             */
/*   Updated: 2024/10/30 18:19:49 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	stlen;

	i = 0;
	if (!s)
		return (NULL);
	stlen = ft_strlen(s);
	if (start >= stlen)
		return (ft_strdup(""));
	if (len > stlen - start)
		len = stlen - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
