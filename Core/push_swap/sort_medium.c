/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:29:55 by pedved            #+#    #+#             */
/*   Updated: 2026/10/10 15:30:15 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_max_position(t_stack *b)
{
	t_list	*current;
	size_t	position;
	size_t	max_position;
	int		max_value;

	current = b->top;
	position = 0;
	max_position = 0;
	max_value = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max_value)
		{
			max_value = *(int *)current->content;
			max_position = position;
		}
		current = current->next;
		position++;
	}
	return (max_position);
}

static void	move_max_to_top(t_stack *b, size_t position)
{
	size_t	count;

	if (position <= b->size / 2)
	{
		count = position;
		while (count-- > 0)
			rb(b);
	}
	else
	{
		count = b->size - position;
		while (count-- > 0)
			rrb(b);
	}
}

int	sort_medium(t_stack *a, t_stack *b)
{
	size_t	chunk_size;

	if (!a || !b || a->size < 2)
		return (SUCCESS);
	if (!rank_stack(a))
		return (FAILURE);
	chunk_size = get_chunk_size(a->size);
	distribute_chunks(a, b, chunk_size);
	while (b->size > 0)
	{
		move_max_to_top(b, find_max_position(b));
		pa(a, b);
	}
	return (SUCCESS);
}
