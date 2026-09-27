/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:43:22 by pedved            #+#    #+#             */
/*   Updated: 2026/08/28 13:27:06 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_len(long n);
static void		get_str(char *s, long nb);
static char		digit_to_char(long digit);

char	*ft_itoa(int n)
{
	long	nb;
	char	*s;
	size_t	n_len;

	nb = n;
	n_len = get_num_len(nb);
	s = malloc(sizeof(char) * (n_len + 1));
	if (s == NULL)
		return (NULL);
	get_str(s, nb);
	return (s);
}

static void	get_str(char *s, long nb)
{
	size_t	i;
	long	divider;

	i = 0;
	if (nb < 0)
	{
		s[i] = '-';
		i++;
		nb *= -1;
	}
	divider = 1;
	while (divider <= nb / 10)
		divider *= 10;
	while (divider > 0)
	{
		s[i] = digit_to_char(nb / divider);
		nb %= divider;
		divider /= 10;
		i++;
	}
	s[i] = '\0';
}

static size_t	get_num_len(long n)
{
	size_t	n_len;

	n_len = 0;
	if (n <= 0)
		n_len++;
	while (n != 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static char	digit_to_char(long digit)
{
	return ((char)digit + '0');
}
