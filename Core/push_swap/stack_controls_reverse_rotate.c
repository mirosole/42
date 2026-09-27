/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controls_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:20:00 by pedved            #+#    #+#             */
/*   Updated: 2026/09/27 15:02:50 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include "stack.h"

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate_reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate_reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	rotate_reverse(a);
	rotate_reverse(b);
	write(1, "rrr\n", 4);
}