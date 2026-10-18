/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:02:54 by pedved            #+#    #+#             */
/*   Updated: 2026/09/18 12:25:56 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Accept a descending gap or the circular minimum-to-maximum gap. */
static int	can_insert_between(int current, int next, int value)
{
	if (current > value && next < value)
		return (SUCCESS);
	if (current < next && (current > value || next < value))
		return (SUCCESS);
	return (FAILURE);
}

static void	rotate_to_position(t_stack *b, size_t position)
{
	size_t	steps;

	if (position <= b->size / 2)
	{
		steps = position;
		while (steps-- > 0)
			rb(b);
	}
	else
	{
		steps = b->size - position;
		while (steps-- > 0)
			rrb(b);
	}
}

/* Lift the gap's next value so pb inserts before it in circular order. */
static void	prepare_b_for_push(t_stack *b, int value)
{
	t_list	*current;
	t_list	*next;
	size_t	position;

	if (b->size < 2)
		return ;
	current = b->top;
	position = 0;
	while (current)
	{
		next = current->next;
		if (!next)
			next = b->top;
		if (can_insert_between(*(int *)current->content,
				*(int *)next->content, value))
			break ;
		position++;
		current = current->next;
	}
	rotate_to_position(b, (position + 1) % b->size);
}

static void	normalize_stack(t_stack *b)
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
		position++;
		current = current->next;
	}
	rotate_to_position(b, max_position);
}

/* Keep B circularly descending, align its maximum, then return to A. */
int	sort_insertion(t_stack *a, t_stack *b)
{
	if (!a || !b || a == b || b->size != 0)
		return (FAILURE);
	if (a->size < 2)
		return (SUCCESS);
	while (a->size > 0)
	{
		prepare_b_for_push(b, *(int *)a->top->content);
		pb(a, b);
	}
	normalize_stack(b);
	while (b->size > 0)
		pa(a, b);
	return (SUCCESS);
}
