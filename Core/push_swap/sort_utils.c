/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:11:22 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/27 11:12:05 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_sorted(t_stack *stack)
{
	t_list	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

size_t	find_min_pos(t_stack *stack)
{
	t_list	*current;
	int		min;
	size_t	pos;
	size_t	min_pos;

	current = stack->top;
	min = *(int *)current->content;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (*(int *)current->content < min)
		{
			min = *(int *)current->content;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

size_t	find_max_pos(t_stack *stack)
{
	t_list	*current;
	int		max;
	size_t	pos;
	size_t	max_pos;

	current = stack->top;
	max = *(int *)current->content;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (*(int *)current->content > max)
		{
			max = *(int *)current->content;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	rotate_a_to(t_stack *a, size_t pos)
{
	size_t	steps;

	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		steps = a->size - pos;
		while (steps-- > 0)
			rra(a);
	}
}

void	rotate_b_to(t_stack *b, size_t pos)
{
	size_t	steps;

	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		steps = b->size - pos;
		while (steps-- > 0)
			rrb(b);
	}
}