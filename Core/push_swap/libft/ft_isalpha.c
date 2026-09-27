/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:29:45 by pedved            #+#    #+#             */
/*   Updated: 2026/08/23 14:17:22 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_lower(int c);
static int	is_upper(int c);

int	ft_isalpha(int c)
{
	return (is_upper(c) || is_lower(c));
}

static int	is_upper(int c)
{
	return (c >= 65 && c <= 90);
}

static int	is_lower(int c)
{
	return (c >= 97 && c <= 122);
}
