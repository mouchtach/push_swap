/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:10:24 by ymouchta          #+#    #+#             */
/*   Updated: 2024/10/31 13:51:03 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static char	**freep(char **p, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static size_t	countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**pcpy(const char *s, char **p, char c, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (j < x)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		p[j++] = ft_substr(s, (unsigned int)start, i - start);
		if (!p[j - 1])
			return (freep(p, j));
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	**result;
	size_t	count;

	if (!s)
		return (NULL);
	count = countwords(s, c);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (NULL);
	result = pcpy(s, p, c, count);
	if (!result)
	{
		free(p);
		return (NULL);
	}
	return (result);
}
