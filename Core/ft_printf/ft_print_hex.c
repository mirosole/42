/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:04:48 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/15 15:09:34 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
	len++;
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_print_str("(nil)"));
	len = 0;
	len += ft_print_str("0x");
	len += ft_print_hex((unsigned long)ptr,
			"0123456789abcdef");
	return (len);
}
