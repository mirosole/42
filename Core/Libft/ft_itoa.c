/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:39:19 by olmirosh          #+#    #+#             */
/*   Updated: 2026/08/28 11:52:54 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	number;
	size_t	len;

	number = n;
	len = ft_numlen(number);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (number < 0)
		result[0] = '-';
	if (number < 0)
		number = -number;
	if (number == 0)
		result[0] = '0';
	while (number > 0)
	{
		result[--len] = number % 10 + '0';
		number /= 10;
	}
	return (result);
}
