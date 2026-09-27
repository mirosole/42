/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:22:17 by pedved            #+#    #+#             */
/*   Updated: 2026/09/15 21:09:38 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void swap(t_stack *s)
{
	if(s->size < 2)
		return; 

	t_list *new_top = s->top->next; 
	t_list *old_top = s->top;
	old_top->next = new_top->next; 
	new_top->next = old_top;  
	s->top = new_top; 
}

// Take the first element at the top of x and put it at the top of y.
// Do nothing if x is empty.
void push(t_stack *x, t_stack *y)
{
	if(!x || !x->top )
		return;
		
	t_list tmp = peek(x);
	pop(x);
	push_element(tmp.content, y); 
}

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void rotate(t_stack *s)
{

	// do nothing if stack is empty or it has 1 elem
	if(!s || !s->top || s->size <= 1)
		return;
		
	t_list new_last = peek(s);

	t_list *curr = s->top;
	while (curr->next != NULL)
	{
		curr->content = curr->next->content;
		curr = curr->next; 
	}
	curr->content = new_last.content; 
}


void rotate_reverse(t_stack *s)
{
if (!s || !s->top || !s->top->next)
  		return ;
	t_list *curr = s->top; 
	while (curr->next->next != NULL)
		curr = curr->next;
	
	t_list *last = curr->next; 
	curr->next = NULL; 
	last->next = s->top;
	s->top = last;  	
}
