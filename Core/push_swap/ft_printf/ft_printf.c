/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 20:58:27 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/12 18:54:40 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_str(char *s);
static int	ft_print_char(char c);
static int	ft_print_long(long n);

int	ft_printf(const char * format, ...)
{
	int	count;
	va_list	args;
    int	length;
	length = 0;
	count = 0;
	va_start(args, format);
	while (format[count])
	{
		if (format[count] != '%')
		{
			ft_putchar_fd(format[count], 1);
			length++;
		}
		else
		{
			length += ft_handle_format(format[count + 1], &args);
			count++;
		}
		count++;
	}
	va_end(args);
	return (length);
}

int	ft_handle_format(char format, va_list *args)
{
	if (format == 'i' || format == 'd')
		return (ft_print_nbr(va_arg(*args, int)));
	if (format == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (format == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (format == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	if (format == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (format == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	if (format == '%')
		return (ft_print_char('%'));
	return (0);
}
static int	ft_print_str(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}
static int ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
static int ft_print_long(long n)
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
	if(n >= 10)
		len += ft_print_long(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
int ft_print_nbr(int n)
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
	write(1, &c, 1);
	len++;
	return (len);
}
int	ft_print_hex(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
	len++;
	return (len);
}
int ft_print_pointer(void *ptr)
{
	int len;

	if(!ptr)
		return (ft_print_str("(nil)"));
	len = 0;
	len += ft_print_str("0x");
	len += ft_print_hex((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
