#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, len + 1);
	return (copy);
}
