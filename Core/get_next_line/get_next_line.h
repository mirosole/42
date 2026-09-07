/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksejmirosnicenko <aleksejmirosnicenk    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:34:27 by aleksejmiro       #+#    #+#             */
/*   Updated: 2026/09/04 16:11:38 by aleksejmiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*read_to_stash(int fd, char *stash);

#endif