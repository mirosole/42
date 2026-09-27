#include "stack.h"
#include <limits.h>

static int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	parse_digits(char *str, int i, long limit, long *value)
{
	int	digit;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		digit = str[i] - '0';
		if (*value > (limit - digit) / 10)
			return (0);
		*value = *value * 10 + digit;
		i++;
	}
	return (1);
}

int	parse_int(char *str, int *result)
{
	long	value;
	long	limit;
	int		sign;
	int		i;

	if (!str || str[0] == '\0')
		return (0);
	value = 0;
	i = 0;
	sign = parse_sign(str, &i);
	if (str[i] == '\0')
		return (0);
	if (sign == 1)
		limit = INT_MAX;
	else
		limit = -(long)INT_MIN;
	if (!parse_digits(str, i, limit, &value))
		return (0);
	*result = (int)(value * sign);
	return (1);
}
