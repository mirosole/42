/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:15:00 by pedved            #+#    #+#             */
/*   Updated: 2026/08/28 13:28:12 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_forward(unsigned char *d, unsigned char *s, size_t len);
static void	copy_backward(unsigned char *d, unsigned char *s, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
		copy_forward(d, s, len);
	else
		copy_backward(d, s, len);
	return (dst);
}

static void	copy_forward(unsigned char *d, unsigned char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
}

static void	copy_backward(unsigned char *d, unsigned char *s, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
}
