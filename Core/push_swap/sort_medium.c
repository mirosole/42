/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:14:07 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/27 11:14:10 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	int_sqrt(size_t number)
{
	size_t	result;

	result = 0;
	while (result + 1 <= number / (result + 1))
		result++;
	return ((int)result);
}

static int	get_range(size_t size)
{
	int	range;

	range = int_sqrt(size);
	range += range / 2;
	if (range < 1)
		range = 1;
	return (range);
}

static void	push_ranges(t_stack *a, t_stack *b, int range)
{
	int	value;

	while (a->size > 0)
	{
		value = *(int *)a->top->content;
		if (value <= (int)b->size)
		{
			pb(a, b);
			rb(b);
		}
		else if (value <= (int)b->size + range)
			pb(a, b);
		else
			ra(a);
	}
}

static void	return_from_b(t_stack *a, t_stack *b)
{
	size_t	pos;

	while (b->size > 0)
	{
		pos = find_max_pos(b);
		rotate_b_to(b, pos);
		pa(a, b);
	}
}

int	sort_medium(t_stack *a, t_stack *b)
{
	int	range;

	if (!a || a->size < 2 || stack_is_sorted(a))
		return (1);
	if (!rank_stack(a))
		return (0);
	range = get_range(a->size);
	push_ranges(a, b, range);
	return_from_b(a, b);
	return (1);
}