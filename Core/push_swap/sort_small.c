/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 15:00:00 by olmirosh          #+#    #+#             */
/*   Updated: 2026/10/18 16:03:12 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_min_position(t_stack *a)
{
	t_list	*current;
	size_t	position;
	size_t	min_position;
	int		min_value;

	current = a->top;
	position = 0;
	min_position = 0;
	min_value = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content < min_value)
		{
			min_value = *(int *)current->content;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	return (min_position);
}

static void	move_min_to_top(t_stack *a)
{
	size_t	position;
	size_t	steps;

	position = find_min_position(a);
	if (position <= a->size / 2)
	{
		steps = position;
		while (steps-- > 0)
			ra(a);
	}
	else
	{
		steps = a->size - position;
		while (steps-- > 0)
			rra(a);
	}
}

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)a->top->content;
	second = *(int *)a->top->next->content;
	third = *(int *)a->top->next->next->content;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

int	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (*(int *)a->top->content > *(int *)a->top->next->content)
			sa(a);
		return (SUCCESS);
	}
	while (a->size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	if (a->size == 3)
		sort_three(a);
	while (b->size > 0)
		pa(a, b);
	return (SUCCESS);
}
