/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirosole <mirosole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:14:33 by mirosole          #+#    #+#             */
/*   Updated: 2026/09/27 11:14:36 by mirosole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

double	compute_disorder(t_stack *stack)
{
	t_list				*first;
	t_list				*second;
	unsigned long long	mistakes;
	unsigned long long	pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	mistakes = 0;
	pairs = 0;
	first = stack->top;
	while (first)
	{
		second = first->next;
		while (second)
		{
			pairs++;
			if (*(int *)first->content > *(int *)second->content)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	return ((double)mistakes / (double)pairs);
}