/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:07:44 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/27 15:07:45 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

#define DECIMAL_BASE 10

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

/* Check the limit before multiplying, so an oversized input cannot overflow. */
static int	parse_digits(char *str, int i, long limit, long *value)
{
	int	digit;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAILURE);
		digit = str[i] - '0';
		if (*value > (limit - digit) / DECIMAL_BASE)
			return (FAILURE);
		*value = *value * DECIMAL_BASE + digit;
		i++;
	}
	return (SUCCESS);
}

/* Parse the magnitude first; negative input may reach INT_MAX + 1. */
int	parse_int(char *str, int *result)
{
	long	value;
	long	limit;
	int		sign;
	int		i;

	if (!str || str[0] == '\0')
		return (FAILURE);
	value = 0;
	i = 0;
	sign = parse_sign(str, &i);
	if (str[i] == '\0')
		return (FAILURE);
	if (sign == 1)
		limit = INT_MAX;
	else
		limit = -(long)INT_MIN;
	if (!parse_digits(str, i, limit, &value))
		return (FAILURE);
	*result = (int)(value * sign);
	return (SUCCESS);
}
