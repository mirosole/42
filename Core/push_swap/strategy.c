/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:46:08 by olmirosh          #+#    #+#             */
/*   Updated: 2026/10/18 16:29:13 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	select_adaptive_strategy(double disorder)
{
	if (disorder < 0.2)
		return (STRATEGY_SIMPLE);
	if (disorder < 0.5)
		return (STRATEGY_MEDIUM);
	return (STRATEGY_COMPLEX);
}

static int	run_strategy(t_stack *a, t_stack *b, t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return (sort_simple(a, b));
	if (strategy == STRATEGY_MEDIUM)
		return (sort_medium(a, b));
	if (strategy == STRATEGY_COMPLEX)
		return (sort_complex(a, b));
	return (FAILURE);
}

static int	run_selected_strategy(t_stack *a, t_stack *b,
		t_strategy strategy)
{
	if (a->size <= 5)
		return (sort_small(a, b));
	return (run_strategy(a, b, strategy));
}

int	sort_input(t_stack *a, t_stack *b, t_config *config)
{
	t_stats		stats;
	t_strategy	strategy;
	double		disorder;
	int			result;

	ft_bzero(&stats, sizeof(stats));
	a->stats = &stats;
	b->stats = &stats;
	disorder = compute_disorder(a);
	strategy = config->strategy;
	if (strategy == STRATEGY_ADAPTIVE)
		strategy = select_adaptive_strategy(disorder);
	result = SUCCESS;
	if (disorder != MIN_DISORDER)
		result = run_selected_strategy(a, b, strategy);
	if (result && config->bench_enabled)
		print_benchmark(&stats, disorder, config->strategy);
	a->stats = NULL;
	b->stats = NULL;
	return (result);
}
