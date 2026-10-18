/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:07:44 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/27 15:07:45 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *a, int number)
{
	t_list	*current;

	current = a->top;
	while (current)
	{
		if (*(int *)current->content == number)
			return (true);
		current = current->next;
	}
	return (false);
}

/* Allocate value and node; release the value if node allocation fails. */
int	add_number(t_stack *a, int number)
{
	int		*value;
	t_list	*node;

	value = malloc(sizeof(int));
	if (!value)
		return (FAILURE);
	*value = number;
	node = ft_lstnew(value);
	if (!node)
	{
		free(value);
		return (FAILURE);
	}
	node->next = a->top;
	a->top = node;
	a->size++;
	return (SUCCESS);
}
