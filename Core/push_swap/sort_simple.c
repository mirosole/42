/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:12:37 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/27 11:12:40 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	sort_simple(t_stack *a, t_stack *b)
{
	size_t	pos;

	if (!a || a->size < 2 || stack_is_sorted(a))
		return (1);
	while (a->size > 0)
	{
		pos = find_min_pos(a);
		rotate_a_to(a, pos);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
	return (1);
}