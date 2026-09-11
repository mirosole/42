/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:06:02 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/11 14:06:03 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*resize_stash(char *stash, size_t used, size_t *capacity)
{
	char	*new_stash;

	if (*capacity < 64)
		*capacity = 64;
	new_stash = malloc(*capacity);
	if (new_stash == NULL)
	{
		free(stash);
		return (NULL);
	}
	if (stash != NULL)
		ft_memcpy(new_stash, stash, used);
	free(stash);
	new_stash[used] = '\0';
	return (new_stash);
}

static int	read_chunk(int fd, char **stash, size_t *used, size_t *capacity)
{
	ssize_t	bytes_read;

	if (*used + 1 + BUFFER_SIZE > *capacity)
	{
		*capacity *= 2;
		*stash = resize_stash(*stash, *used, capacity);
		if (stash == NULL)
			return (-1);
	}
	bytes_read = read(fd, *stash + *used, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	if (bytes_read == 0)
		return (0);
	*used += bytes_read;
	(*stash)[*used] = '\0';
	return (1);
}

char	*read_to_stash(int fd, char *stash)
{
	size_t	capacity;
	size_t	used;
	int		status;

	if (stash != NULL && ft_strchr(stash, '\n') != NULL)
		return (stash);
	used = 0;
	if (stash != NULL)
		used = ft_strlen(stash);
	capacity = used + BUFFER_SIZE + 1;
	stash = resize_stash(stash, used, &capacity);
	if (stash == NULL)
		return (NULL);
	while (ft_strchr(stash, '\n') == NULL)
	{
		status = read_chunk(fd, &stash, &used, &capacity);
		if (status <= 0)
			break ;
	}
	if (status < 0)
		return (NULL);
	return (stash);
}

static char	*gnl_core(int fd, char **stash)
{
	char	*line;
	char	*tmp;
	char	*newline;

	*stash = read_to_stash(fd, *stash);
	if (*stash == NULL || (*stash)[0] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	newline = ft_strchr(*stash, '\n');
	if (newline == NULL)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, newline - *stash + 1);
	tmp = ft_substr(*stash, newline - *stash + 1, ft_strlen(*stash));
	free(*stash);
	*stash = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	return (gnl_core(fd, &stash));
}
