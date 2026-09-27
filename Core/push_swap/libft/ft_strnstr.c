/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 14:49:55 by pedved            #+#    #+#             */
/*   Updated: 2026/08/23 16:25:04 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_strings(char *string, char *substring);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	int		compatarion;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	len_little = ft_strlen(little);
	while (big[i] != '\0' && i < len && (len - i >= len_little))
	{
		compatarion = compare_strings(((char *)(big + i)), (char *)little);
		if (compatarion)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

static int	compare_strings(char *string, char *substring)
{
	size_t	i;

	i = 0;
	while (substring[i] != '\0')
	{
		if (string[i] != substring[i] || string[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}
