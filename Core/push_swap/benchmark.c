/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:55:58 by olmirosh          #+#    #+#             */
/*   Updated: 2026/10/10 14:55:59 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_size_t_fd(size_t number, int fd)
{
	char	c;

	if (number >= 10)
		put_size_t_fd(number / 10, fd);
	c = '0' + (number % 10);
	write(fd, &c, 1);
}

static void	print_disorder(double disorder)
{
	size_t	percent;

	percent = (size_t)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("Disorder: ", 2);
	put_size_t_fd(percent / 100, 2);
	write(2, ".", 1);
	if (percent % 100 < 10)
		write(2, "0", 1);
	put_size_t_fd(percent % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_strategy strategy, double disorder)
{
	ft_putstr_fd("Strategy: ", 2);
	if (strategy == STRATEGY_ADAPTIVE)
	{
		ft_putstr_fd("adaptive -> ", 2);
		strategy = select_adaptive_strategy(disorder);
	}
	if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("simple\nComplexity: O(n^2)\n", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("medium\nComplexity: O(n*sqrt(n))\n", 2);
	else if (strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("complex\nComplexity: O(n log n)\n", 2);
}

static void	print_operation(char *name, size_t count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	put_size_t_fd(count, 2);
	write(2, "\n", 1);
}

void	print_benchmark(t_stats *stats, double disorder, t_strategy strategy)
{
	print_disorder(disorder);
	print_strategy(strategy, disorder);
	ft_putstr_fd("Total operations: ", 2);
	put_size_t_fd(stats->total, 2);
	write(2, "\n", 1);
	print_operation("sa", stats->sa);
	print_operation("sb", stats->sb);
	print_operation("ss", stats->ss);
	print_operation("pa", stats->pa);
	print_operation("pb", stats->pb);
	print_operation("ra", stats->ra);
	print_operation("rb", stats->rb);
	print_operation("rr", stats->rr);
	print_operation("rra", stats->rra);
	print_operation("rrb", stats->rrb);
	print_operation("rrr", stats->rrr);
}
