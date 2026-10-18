/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:20:00 by pedved            #+#    #+#             */
/*   Updated: 2026/10/10 15:00:57 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!b || b->size == 0)
		return ;
	push(b, a);
	if (a->stats)
	{
		a->stats->pa++;
		a->stats->total++;
	}
	write(STDOUT_FILENO, "pa\n", sizeof("pa\n") - 1);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || a->size == 0)
		return ;
	push(a, b);
	if (a->stats)
	{
		a->stats->pb++;
		a->stats->total++;
	}
	write(STDOUT_FILENO, "pb\n", sizeof("pb\n") - 1);
}
