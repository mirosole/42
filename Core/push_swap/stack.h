/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:43:43 by pedved            #+#    #+#             */
/*   Updated: 2026/09/27 18:36:47 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
# include <unistd.h>

typedef struct stack
{
	t_list *top; 
	size_t size;  
	
} t_stack; 

typedef enum t_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}	t_strategy;
typedef struct bench
{
	t_strategy	strategy;
	int			bench;
	int			strategy_set;
}	t_config;

// Stack utils

// Add a value to a stack; this prototype still needs a stack parameter.
void push_element(void *value, t_stack *stack); 
// Remove the top node from the stack.
void pop(t_stack *s);
// Return a copy of the top list node without removing it.
t_list peek(t_stack *s);
// Return nonzero when the stack has no nodes.
size_t is_empty(t_stack *s);
// Create a new stack without mem allocation
t_stack init_stack();
// free the whole stack
void free_stack(t_stack *stack);
// Swap the first two elements at the top of stack
void swap(t_stack *s); 
// Take the first element at the top of x and put it at the top of y
void push(t_stack *x, t_stack *y);
// Shift up all elements of stack by one
void rotate(t_stack *s);
// Shift down all elements of stack  by one
void rotate_reverse(t_stack *s);


// Stack control commands
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);


// Stack sort functions

// O(N^2)
void sort_stack_O2(t_stack *a, t_stack *b);
void prepare_b_for_push(t_stack *s, int value);
void rotate_stack(t_stack *s, size_t depth);
void normilize_stack(t_stack *s);
#endif

//Parser
int		parse_arguments(int argc, char **argv,
			t_stack *a, t_config *config);
int		parse_int(char *str, int *result);
int		has_duplicate(t_stack *a, int number);
int		add_number(t_stack *a, int number);
void	free_parsed_stack(t_stack *stack);

//sort utils

int		stack_is_sorted(t_stack *stack);
size_t	find_min_pos(t_stack *stack);
size_t	find_max_pos(t_stack *stack);
void	rotate_a_to(t_stack *a, size_t pos);
void	rotate_b_to(t_stack *b, size_t pos);

//sort simple
int	sort_simple(t_stack *a, t_stack *b);

//sort rank
int	rank_stack(t_stack *stack);

//sort coplex
int	sort_complex(t_stack *a, t_stack *b);

//sort medium
int	sort_medium(t_stack *a, t_stack *b);

//disorder
double	compute_disorder(t_stack *stack);