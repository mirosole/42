/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:07:44 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/27 15:07:45 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack)
{
	int		*array;
	t_list	*current;
	size_t	i;

	array = malloc(sizeof(int) * stack->size);
	if (array == NULL)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		array[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	return (array);
}

static size_t	find_rank(int *sorted, size_t size, int value)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = size;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

int	rank_stack(t_stack *stack)
{
	int		*sorted;
	t_list	*current;
	size_t	rank;

	if (stack == NULL || stack->size == 0)
		return (1);
	sorted = stack_to_array(stack);
	if (sorted == NULL)
		return (0);
	if (!sort_array(sorted, stack->size))
	{
		free(sorted);
		return (0);
	}
	current = stack->top;
	while (current)
	{
		rank = find_rank(sorted, stack->size,
				*(int *)current->content);
		*(int *)current->content = (int)rank;
		current = current->next;
	}
	free(sorted);
	return (1);
}
