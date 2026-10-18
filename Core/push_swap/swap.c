/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:20:00 by pedved            #+#    #+#             */
/*   Updated: 2026/10/17 18:39:56 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	swap(a);
	if (a->stats)
	{
		a->stats->sa++;
		a->stats->total++;
	}
	write(STDOUT_FILENO, "sa\n", sizeof("sa\n") - 1);
}

void	sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	swap(b);
	if (b->stats)
	{
		b->stats->sb++;
		b->stats->total++;
	}
	write(STDOUT_FILENO, "sb\n", sizeof("sb\n") - 1);
}

void	ss(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	swap(a);
	swap(b);
	if (a->stats)
	{
		a->stats->ss++;
		a->stats->total++;
	}
	write(STDOUT_FILENO, "ss\n", sizeof("ss\n") - 1);
}
