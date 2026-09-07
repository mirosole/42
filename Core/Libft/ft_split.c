#include "libft.h"

static size_t	count_words(char const *s, char c)
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

static void	free_words(char **result, size_t words_created)
{
	size_t	i;

	i = 0;
	while (i < words_created)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	add_word(char **result, const char *s, size_t start,
		size_t end, size_t word)
{
	result[word] = ft_substr(s, start, end - start);
	if (result[word] == NULL)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	start;
	size_t	word;

	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start && !add_word(result, s, start, i, word))
			return (free_words(result, word), NULL);
		if (i > start)
			word++;
	}
	result[word] = NULL;
	return (result);
}
