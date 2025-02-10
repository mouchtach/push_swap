/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:27:19 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/07 21:27:34 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_free(char **maloc)
{
	if (maloc && *maloc)
	{
		free(*maloc);
		*maloc = NULL;
	}
	return (NULL);
}

static void	ft_cpy(char **dst, char **src)
{
	int	i;

	i = 0;
	if (*dst && *src)
	{
		while ((*src)[i] && (*src)[i] != '\n')
		{
			(*dst)[i] = (*src)[i];
			i++;
		}
		(*dst)[i] = '\0';
	}
}

static char	*extra_line(char **line)
{
	int		i;
	char	*dst;
	char	*temp;

	i = 0;
	if (!line && !*line)
		return (NULL);
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (NULL);
	ft_cpy(&dst, line);
	temp = ft_strdup_get((*line) + i);
	if (!temp)
		return (ft_free(line), ft_free(&dst));
	ft_free(line);
	*line = temp;
	return (dst);
}

static char	*ft_get_line(int fd, char **line)
{
	char	*temp;
	char	*buffer;
	int		nb;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(line));
	while (1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb < 0)
			return (ft_free(&buffer), ft_free(line));
		buffer[nb] = '\0';
		temp = ft_strjoin_get(*line, buffer);
		if (!temp)
			return (ft_free(&buffer), ft_free(line));
		ft_free(line);
		*line = temp;
		if (ft_strchr_get(*line, '\n') || nb == 0)
			break ;
	}
	ft_free(&buffer);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*extra;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_get_line(fd, &line);
	if (!line)
		return (ft_free(&line));
	extra = extra_line(&line);
	if (!extra || ft_strlen_get(extra) == 0)
		return (ft_free(&extra), ft_free(&line));
	return (extra);
}
