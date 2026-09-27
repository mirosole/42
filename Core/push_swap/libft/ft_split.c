/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:26:11 by pedved            #+#    #+#             */
/*   Updated: 2026/08/26 15:30:27 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words_count(char const *s, char c);
static t_word	*fill_words(char const *s, char c, size_t words_count);
static t_word	get_word(char const *s, char c, size_t *i);
static void		*free_words_info(t_word *words, size_t words_count);

char	**ft_split(char const *s, char c)
{
	t_word	*words_info;
	char	**words;
	size_t	words_count;
	size_t	i;

	if (s == NULL)
		return (NULL);
	words_count = get_words_count(s, c);
	words_info = fill_words(s, c, words_count);
	if (words_count > 0 && words_info == NULL)
		return (NULL);
	words = ft_calloc(words_count + 1, sizeof(*words));
	if (words == NULL)
		return (free_words_info(words_info, words_count));
	i = 0;
	while (i < words_count)
	{
		words[i] = words_info[i].word;
		i++;
	}
	free(words_info);
	return (words);
}

static size_t	get_words_count(char const *s, char c)
{
	size_t	s_len;
	size_t	words_count;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len == 0 || (s_len == 1 && s[0] == c))
		return (0);
	if (s_len == 1)
		return (1);
	words_count = 0;
	i = 1;
	while (s[i] != '\0')
	{
		if (i == 1 && s[i - 1] != c)
		{
			words_count++;
			i++;
			continue ;
		}
		if (s[i] != c && s[i - 1] == c)
			words_count++;
		i++;
	}
	return (words_count);
}

static t_word	*fill_words(char const *s, char c, size_t words_count)
{
	t_word	*words;
	size_t	j;
	size_t	i;

	if (words_count == 0)
		return (NULL);
	words = malloc(sizeof(*words) * words_count);
	if (words == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (j < words_count)
	{
		words[j] = get_word(s, c, &i);
		words[j].word = ft_substr(s, words[j].start, words[j].len);
		if (words[j].word == NULL)
			return (free_words_info(words, j));
		j++;
	}
	return (words);
}

static t_word	get_word(char const *s, char c, size_t *i)
{
	t_word	word;

	word.word = NULL;
	word.start = 0;
	word.len = 0;
	while (s[*i] == c && s[*i] != '\0')
		*i += 1;
	word.start = *i;
	while (s[*i] != c && s[*i] != '\0')
	{
		word.len += 1;
		*i += 1;
	}
	return (word);
}

static void	*free_words_info(t_word *words, size_t words_count)
{
	size_t	i;

	if (words == NULL)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		free(words[i].word);
		i++;
	}
	free(words);
	return (NULL);
}
