#include "libft.h"

static size_t	number_len(long number)
{
	size_t	len;

	len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new;
	long	number;
	size_t	len;

	number = n;
	len = number_len(number);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	new[len] = '\0';
	if (number < 0)
		number = -number;
	while (len > 0 && new[len - 1] != '-')
	{
		new[--len] = (char)(number % 10 + '0');
		number /= 10;
		if (number == 0)
			break ;
	}
	if (n < 0)
		new[0] = '-';
	return (new);
}
