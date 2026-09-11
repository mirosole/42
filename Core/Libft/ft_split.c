/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 11:40:16 by olmirosh          #+#    #+#             */
/*   Updated: 2026/08/25 13:17:50 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free_split(char **result, size_t count)
{
	while (count > 0)
	{
		count--;
		free(result[count]);
	}
	free(result);
	return (NULL);
}

static size_t	ft_next_word(char const *s, char c, size_t *i)
{
	size_t	len;

	while (s[*i] == c)
		(*i)++;
	len = 0;
	while (s[*i + len] != c && s[*i + len] != '\0')
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	word;
	size_t	len;

	result = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		len = ft_next_word(s, c, &i);
		if (len == 0)
			break ;
		result[word] = ft_substr(s, i, len);
		if (result[word] == NULL)
			return (ft_free_split(result, word));
		word++;
		i += len;
	}
	return (result);
}
