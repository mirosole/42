/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:20:00 by pedved            #+#    #+#             */
/*   Updated: 2026/10/10 15:06:19 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate_reverse(a);
	if (a->stats)
	{
		a->stats->rra++;
		a->stats->total++;
	}
	write(STDOUT_FILENO, "rra\n", sizeof("rra\n") - 1);
}

void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate_reverse(b);
	if (b->stats)
	{
		b->stats->rrb++;
		b->stats->total++;
	}
	write(STDOUT_FILENO, "rrb\n", sizeof("rrb\n") - 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	rotate_reverse(a);
	rotate_reverse(b);
	if (a->stats)
	{
		a->stats->rrr++;
		a->stats->total++;
	}
	write(STDOUT_FILENO, "rrr\n", sizeof("rrr\n") - 1);
}
