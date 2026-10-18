/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:50:48 by pedved            #+#    #+#             */
/*   Updated: 2026/10/10 14:59:08 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(void)
{
	t_stack	stack;

	stack.top = NULL;
	stack.size = 0;
	stack.stats = NULL;
	return (stack);
}

void	clear_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
