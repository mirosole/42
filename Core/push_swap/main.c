/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:46:08 by olmirosh          #+#    #+#             */
/*   Updated: 2026/10/10 16:07:18 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ERROR_MESSAGE "Error\n"

static void	init_config(t_config *config)
{
	config->strategy = STRATEGY_ADAPTIVE;
	config->bench_enabled = false;
	config->strategy_set = false;
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;
	int			result;

	if (argc == 1)
		return (EXIT_SUCCESS);
	a = init_stack();
	b = init_stack();
	init_config(&config);
	result = parse_arguments(argc, argv, &a, &config);
	if (result)
		result = sort_input(&a, &b, &config);
	if (!result)
		write(STDERR_FILENO, ERROR_MESSAGE, sizeof(ERROR_MESSAGE) - 1);
	clear_stack(&a);
	clear_stack(&b);
	if (!result)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
