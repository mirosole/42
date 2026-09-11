/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 11:40:27 by olmirosh          #+#    #+#             */
/*   Updated: 2026/08/25 11:40:28 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	new_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		new_len = 0;
	else if (len > s_len - start)
		new_len = s_len - start;
	else
		new_len = len;
	result = malloc(new_len + 1);
	if (result == NULL)
		return (NULL);
	if (new_len > 0)
		ft_memcpy(result, s + start, new_len);
	result[new_len] = '\0';
	return (result);
}
