/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:10:46 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/27 18:36:42 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	find_min_position(t_stack *a)
{
	t_list	*current;
	int current_value;
	int	min_value;
	size_t	position;
	size_t	min_position;

	position = 0;
	min_position = 0;
	current = a->top;
	min_value = *(int *)a->top->content;
	while (current)
	{
		current_value = *(int *)current->content;
		if (current_value < min_value)
		{
			min_value = *(int *)current->content;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	return (min_position);
}

void	move_min_to_top(t_stack	*a, size_t	min_position)
{
	size_t	rotate_cost = min_position;
	size_t	reverse_rotate_cost = a->size - min_position;
	size_t	count;

	count = 0;
	if(rotate_cost <= reverse_rotate_cost)
	{
		while (count < rotate_cost)
		{
			ra(a);
			count++;
		}
	}
	else
	{
		while (count < reverse_rotate_cost)
		{
			rra(a);
			count++;
		}	
	}	
}
int	sort_simple(t_stack *a, t_stack *b)
{
	size_t	min_position;

	while (a->size > 0)
	{
		min_position = find_min_position(a);
		move_min_to_top(a, min_position);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
	return (1);
}