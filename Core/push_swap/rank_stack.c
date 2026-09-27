/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:13:08 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/27 11:13:12 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	count_smaller(t_stack *stack, int value)
{
	t_list	*current;
	int		count;

	count = 0;
	current = stack->top;
	while (current)
	{
		if (*(int *)current->content < value)
			count++;
		current = current->next;
	}
	return (count);
}

int	rank_stack(t_stack *stack)
{
	t_list	*current;
	int		*ranks;
	size_t	i;

	if (!stack || stack->size == 0)
		return (1);
	ranks = malloc(sizeof(int) * stack->size);
	if (!ranks)
		return (0);
	current = stack->top;
	i = 0;
	while (current)
	{
		ranks[i++] = count_smaller(stack, *(int *)current->content);
		current = current->next;
	}
	current = stack->top;
	i = 0;
	while (current)
	{
		*(int *)current->content = ranks[i++];
		current = current->next;
	}
	free(ranks);
	return (1);
}