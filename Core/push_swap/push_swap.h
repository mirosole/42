/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:43:43 by pedved            #+#    #+#             */
/*   Updated: 2026/10/18 15:28:27 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

/* Internal helpers return nonzero on success. */
# define SUCCESS 1
# define FAILURE 0
# define MIN_DISORDER 0.0

typedef enum e_strategy
{
	STRATEGY_INVALID = -1,
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}	t_strategy;

typedef struct s_stats
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	size_t	total;
}	t_stats;

typedef struct s_stack
{
	t_list		*top;
	size_t		size;
	t_stats		*stats;
}	t_stack;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench_enabled;
	int			strategy_set;
}	t_config;

t_stack			init_stack(void);
void			swap(t_stack *s);
void			push(t_stack *x, t_stack *y);
void			rotate(t_stack *s);
void			rotate_reverse(t_stack *s);

void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

int				parse_arguments(int argc, char **argv,
					t_stack *a, t_config *config);
int				parse_int(char *str, int *result);
int				has_duplicate(t_stack *a, int number);
int				add_number(t_stack *a, int number);
void			clear_stack(t_stack *stack);

int				sort_simple(t_stack *a, t_stack *b);
int				sort_small(t_stack *a, t_stack *b);
int				sort_insertion(t_stack *a, t_stack *b);

int				rank_stack(t_stack *stack);

int				sort_complex(t_stack *a, t_stack *b);

int				sort_medium(t_stack *a, t_stack *b);

double			compute_disorder(t_stack *stack);

int				sort_array(int *array, size_t size);

void			print_benchmark(t_stats *stats, double disorder,
					t_strategy strategy);
t_strategy		select_adaptive_strategy(double disorder);
size_t			get_chunk_size(size_t size);
void			distribute_chunks(t_stack *a, t_stack *b, size_t chunk_size);

int				sort_input(t_stack *a, t_stack *b, t_config *config);

#endif
