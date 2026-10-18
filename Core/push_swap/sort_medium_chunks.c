/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_chunks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:07:44 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/27 15:07:45 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_chunk_size(size_t size)
{
	size_t	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

static void	push_chunk(t_stack *a, t_stack *b,
	size_t min_rank, size_t max_rank)
{
	size_t	to_check;
	int		value;

	to_check = a->size;
	while (to_check > 0)
	{
		value = *(int *)a->top->content;
		if ((size_t)value >= min_rank && (size_t)value <= max_rank)
			pb(a, b);
		else
			ra(a);
		to_check--;
	}
}

void	distribute_chunks(t_stack *a, t_stack *b, size_t chunk_size)
{
	size_t	size;
	size_t	start;
	size_t	end;

	size = a->size;
	start = 0;
	while (start < size)
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		push_chunk(a, b, start, end);
		start += chunk_size;
	}
}
