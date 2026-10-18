/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:20:00 by pedved            #+#    #+#             */
/*   Updated: 2026/10/10 15:01:50 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate(a);
	if (a->stats)
	{
		a->stats->ra++;
		a->stats->total++;
	}
	write(STDOUT_FILENO, "ra\n", sizeof("ra\n") - 1);
}

void	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate(b);
	if (b->stats)
	{
		b->stats->rb++;
		b->stats->total++;
	}
	write(STDOUT_FILENO, "rb\n", sizeof("rb\n") - 1);
}

void	rr(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	rotate(a);
	rotate(b);
	if (a->stats)
	{
		a->stats->rr++;
		a->stats->total++;
	}
	write(1, "rr\n", 3);
}
