/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controls_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:20:00 by pedved            #+#    #+#             */
/*   Updated: 2026/09/27 15:02:51 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!b || b->size == 0)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || a->size == 0)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}