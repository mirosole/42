/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 20:58:27 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/10 22:14:37 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int ft_printf(const char * format, ...)
{
    //int	lenght;
	int	count;
	va_list	args;
	
	count = 0;
	va_start(args, format);
	while (format[count])
	{
		if(format[count] != '%')
			write(1, &format[count], 1);
		else
		{
			ft_handle_format(format[count + 1], &args);
			count++;
		}
		count++;
	}
	va_end(args);
	return (count);
}

void ft_handle_format(char format,va_list args)
{
	int number;
	if(format == 'i' ||	format == 'd')
		number = va_arg(args, int);

	// etc
}

int main()
{
	int a = ft_printf("11%111");
	return a;
}
