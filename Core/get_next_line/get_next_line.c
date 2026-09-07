/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksejmirosnicenko <aleksejmirosnicenk    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:34:23 by aleksejmiro       #+#    #+#             */
/*   Updated: 2026/09/04 16:29:55 by aleksejmiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_error(char *spoon, char *stash)
{
	free(spoon);
	free(stash);
	return (NULL);
}

char	*read_to_stash(int fd, char *stash)
{
	char		*spoon;
	char		*tmp;
	ssize_t		bytes_read;

	spoon = malloc(BUFFER_SIZE + 1);
	if (spoon == NULL)
		return (NULL);
	while (stash == NULL || ft_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, spoon, BUFFER_SIZE);
		if (bytes_read < 0)
			return (read_error(spoon, stash));
		if (bytes_read == 0)
			break ;
		spoon[bytes_read] = '\0';
		tmp = ft_strjoin(stash, spoon);
		if (tmp == NULL)
			return (read_error(spoon, stash));
		free(stash);
		stash = tmp;
	}
	free(spoon);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*newline;
	char		*tmp;

	stash = read_to_stash(fd, stash);
	if (stash == NULL || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	newline = ft_strchr(stash, '\n');
	if (newline == NULL)
	{
		line = stash;
		stash = NULL;
		return (line);
	}
	line = ft_substr(stash, 0, newline - stash + 1);
	tmp = ft_substr(stash, newline - stash + 1, ft_strlen(stash));
	free(stash);
	stash = tmp;
	return (line);
}
