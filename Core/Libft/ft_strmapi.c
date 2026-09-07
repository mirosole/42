#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = f((unsigned int)i, s[i]);
		i++;
	}
	new[len] = '\0';
	return (new);
}
