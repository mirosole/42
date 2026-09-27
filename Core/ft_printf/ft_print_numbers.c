/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:04:36 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/15 15:09:31 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_long(long n)
{
	int		len;
	char	c;

	len = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		len++;
	}
	if (n >= 10)
		len += ft_print_long(n / 10);
	c = (n % 10) + '0';
	ft_putchar_fd(c, 1);
	len++;
	return (len);
}

int	ft_print_nbr(int n)
{
	return (ft_print_long((long)n));
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	c = (n % 10) + '0';
	ft_putchar_fd(c, 1);
	len++;
	return (len);
}
