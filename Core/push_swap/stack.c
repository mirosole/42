/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:50:48 by pedved            #+#    #+#             */
/*   Updated: 2026/09/13 14:55:18 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Basic stack helpers.
// Add a value to a stack;
void push_element(void *value, t_stack *stack)
{
	t_list *new_top = ft_lstnew(value);
	// if(new_top == NULL)
	// TODO todo
	new_top->next = stack->top; 
	stack->top = new_top; 
	stack->size += 1; 
}


// Remove the top node from the stack.
void pop(t_stack *s)
{

	if( s == NULL|| s->top == NULL)
		return;
		
	t_list *tmp; 
	tmp = s->top->next;
	free(s->top); 
	s->top = tmp; 
	s->size--;
}

// Return a copy of the top list node without removing it.
t_list peek(t_stack *s)
{
	t_list top_node = *s->top; 
	return top_node;
}

// Return nonzero when the stack has no nodes.
size_t is_empty(t_stack *s)
{
	return(s->size == 0);
}


t_stack init_stack()
{
	t_stack stack; 
	stack.size = 0; 
	stack.top = NULL; 
	return stack; 
}

void free_stack(t_stack *stack)
{
	if(stack == NULL || stack->top == NULL)
	{
		stack->size = 0;	
		return;
	}

	t_list *cur_node = stack->top; 
	
	while (cur_node->next != NULL)
	{
		t_list *tmp = cur_node->next; 
		free(cur_node); 
		cur_node = tmp;
	}
	stack->top = NULL; 
	stack->size = 0; 
}