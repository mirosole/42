/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:13:40 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/27 11:13:43 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	get_max_bits(size_t size)
{
	size_t	max;
	int		bits;

	if (size < 2)
		return (1);
	max = size - 1;
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_stack *a, t_stack *b, int bit)
{
	size_t	count;
	int		value;

	count = a->size;
	while (count-- > 0)
	{
		value = *(int *)a->top->content;
		if (((value >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
	}
	while (b->size > 0)
		pa(a, b);
}

int	sort_complex(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;

	if (!a || a->size < 2 || stack_is_sorted(a))
		return (1);
	if (!rank_stack(a))
		return (0);
	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit);
		bit++;
	}
	return (1);
}