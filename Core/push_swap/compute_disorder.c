/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:28:47 by pedved            #+#    #+#             */
/*   Updated: 2026/10/09 16:00:29 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Count inversions in the original order, before any stack operations. */
double	compute_disorder(t_stack *s)
{
	double	pairs;
	double	mistakes;
	t_list	*i;
	t_list	*j;

	if (!s || !s->top || s->size <= 1)
		return (MIN_DISORDER);
	pairs = ((double)s->size * (s->size - 1)) / 2;
	mistakes = 0;
	i = s->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)i->content > *(int *)j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / pairs);
}
