#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	sub_len;

	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	new = malloc(sub_len + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s + start, sub_len);
	new[sub_len] = '\0';
	return (new);
}
