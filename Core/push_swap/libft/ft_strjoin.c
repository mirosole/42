/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:24:21 by pedved            #+#    #+#             */
/*   Updated: 2026/08/28 12:22:46 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_total_len(char const *s1, char const *s2);
static void		fill_join(char *s, char const *s1, char const *s2,
					size_t s_len);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	s_len;

	s_len = get_total_len(s1, s2);
	s = malloc(sizeof(char) * s_len + 1);
	if (s == NULL)
		return (NULL);
	fill_join(s, s1, s2, s_len);
	return (s);
}

static void	fill_join(char *s, char const *s1, char const *s2, size_t s_len)
{
	size_t	s1_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	i = 0;
	j = 0;
	while (i < s_len)
	{
		if (i < s1_len)
			s[i] = s1[i];
		else
		{
			s[i] = s2[j];
			j++;
		}
		i++;
	}
	s[i] = '\0';
}

static size_t	get_total_len(char const *s1, char const *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	return (len);
}
