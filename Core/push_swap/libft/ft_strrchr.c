/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:36:31 by pedved            #+#    #+#             */
/*   Updated: 2026/08/21 14:47:35 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	s_len;

	if (c < 0 || c > 255)
	{
		while (c < 0 || c > 255)
			c %= 256;
	}
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	s_len = (long)ft_strlen(s);
	while (s_len >= 0)
	{
		if (s[s_len] == c)
			return ((char *)(s + s_len));
		s_len--;
	}
	return (NULL);
}
