/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:27:05 by pedved            #+#    #+#             */
/*   Updated: 2026/08/23 17:30:57 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_2_digit(char digit);
static int	check_whitespace(char c);

int	ft_atoi(const char *str)
{
	char	*str_tmp;
	size_t	i;
	int		sign;
	int		res;

	str_tmp = (char *)str;
	i = 0;
	sign = 1;
	res = 0;
	while (check_whitespace(str_tmp[i]))
		i++;
	if (str_tmp[i] == '+')
		i++;
	else if (str_tmp[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str_tmp[i]))
	{
		res *= 10;
		res += char_2_digit(str_tmp[i]);
		i++;
	}
	return (res * sign);
}

static int	char_2_digit(char digit)
{
	int	res;

	res = (int)digit - 48;
	return (res);
}

static int	check_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
