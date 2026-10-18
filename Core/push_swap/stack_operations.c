/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:22:17 by pedved            #+#    #+#             */
/*   Updated: 2026/09/15 21:09:38 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_list	*new_top;
	t_list	*old_top;

	if (s->size < 2)
		return ;
	new_top = s->top->next;
	old_top = s->top;
	old_top->next = new_top->next;
	new_top->next = old_top;
	s->top = new_top;
}

void	push(t_stack *x, t_stack *y)
{
	t_list	*node;

	if (!x || !y || x == y || !x->top)
		return ;
	node = x->top;
	x->top = node->next;
	x->size--;
	node->next = y->top;
	y->top = node;
	y->size++;
}

void	rotate(t_stack *s)
{
	t_list	*current;
	void	*first;

	if (!s || !s->top || s->size <= 1)
		return ;
	first = s->top->content;
	current = s->top;
	while (current->next)
	{
		current->content = current->next->content;
		current = current->next;
	}
	current->content = first;
}

void	rotate_reverse(t_stack *s)
{
	t_list	*current;
	t_list	*last;

	if (!s || !s->top || !s->top->next)
		return ;
	current = s->top;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = s->top;
	s->top = last;
}
