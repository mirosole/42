/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:53:37 by pedved            #+#    #+#             */
/*   Updated: 2026/08/25 13:29:20 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_substr_len(char const *s, unsigned int start, size_t len);
static char		*get_empty_str(void);
static void		fill_substr(char *substr, char const *s,
					unsigned int start, size_t substr_len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (get_empty_str());
	substr_len = get_substr_len(s, start, len);
	substr = malloc(sizeof(char) * substr_len + 1);
	if (substr == NULL)
		return (NULL);
	fill_substr(substr, s, start, substr_len);
	return (substr);
}

static char	*get_empty_str(void)
{
	char	*substr;

	substr = malloc(1);
	if (substr == NULL)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

static void	fill_substr(char *substr, char const *s, unsigned int start,
		size_t substr_len)
{
	size_t	i;

	i = 0;
	while (i < substr_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
}

static size_t	get_substr_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		i++;
	}
	return (i);
}
