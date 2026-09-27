/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:28:47 by pedved            #+#    #+#             */
/*   Updated: 2026/09/27 15:52:51 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

double compute_disorder(t_stack *s)
{
	// a formula to calculate all possible pairs
	
	if(!s || !s->top || s->size <=1)
		return (0.0);
	double pairs = (s->size * (s->size - 1)) / 2;
	
	
	double mistakes = 0; 

	t_list *i = s->top;
	t_list *j;
	
	while (i)
	{
		j = i->next;  
		while (j)
		{
		if(*(int *)i->content > *(int *)j->content)
			mistakes++; 
		j = j->next; 
		}
		i = i->next; 
	}
	return (mistakes / pairs); 
}