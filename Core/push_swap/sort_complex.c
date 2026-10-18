/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:07:44 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/27 15:07:45 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_bit(t_stack *a, t_stack *b, size_t size, size_t bit)
{
	size_t	remaining;

	remaining = size;
	while (remaining-- > 0)
	{
		if (((*(int *)a->top->content >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
	}
	while (b->size > 0)
		pa(a, b);
}

/* Stable binary partitions, from the least significant rank bit upwards. */
int	sort_complex(t_stack *a, t_stack *b)
{
	size_t	size;
	size_t	max_rank;
	size_t	bit;

	if (!a || !b || a == b || b->size != 0)
		return (FAILURE);
	if (a->size < 2)
		return (SUCCESS);
	if (!rank_stack(a))
		return (FAILURE);
	size = a->size;
	max_rank = size - 1;
	bit = 0;
	while (max_rank != 0)
	{
		sort_bit(a, b, size, bit);
		bit++;
		max_rank >>= 1;
	}
	return (SUCCESS);
}
