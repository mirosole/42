/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:07:44 by olmirosh          #+#    #+#             */
/*   Updated: 2026/09/27 15:07:45 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Compare the terminator too, so a flag with extra trailing text is invalid. */
static t_strategy	parse_strategy(char *arg)
{
	if (ft_strncmp(arg, "--simple", ft_strlen("--simple") + 1) == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strncmp(arg, "--medium", ft_strlen("--medium") + 1) == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strncmp(arg, "--complex", ft_strlen("--complex") + 1) == 0)
		return (STRATEGY_COMPLEX);
	if (ft_strncmp(arg, "--adaptive", ft_strlen("--adaptive") + 1) == 0)
		return (STRATEGY_ADAPTIVE);
	return (STRATEGY_INVALID);
}

/* Allow one strategy and one --bench flag; reject repeats and unknown flags. */
static int	parse_flag(char *arg, t_config *config)
{
	t_strategy	strategy;

	if (ft_strncmp(arg, "--bench", ft_strlen("--bench") + 1) == 0)
	{
		if (config->bench_enabled)
			return (FAILURE);
		config->bench_enabled = true;
		return (SUCCESS);
	}
	if (config->strategy_set)
		return (FAILURE);
	strategy = parse_strategy(arg);
	if (strategy == STRATEGY_INVALID)
		return (FAILURE);
	config->strategy = strategy;
	config->strategy_set = true;
	return (SUCCESS);
}

/* Read backwards because each number is pushed onto the top of A. */
int	parse_arguments(int argc, char **argv,
		t_stack *a, t_config *config)
{
	int	i;
	int	number;

	i = argc - 1;
	while (i > 0)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!parse_flag(argv[i], config))
				return (FAILURE);
		}
		else
		{
			if (!parse_int(argv[i], &number))
				return (FAILURE);
			if (has_duplicate(a, number) || !add_number(a, number))
				return (FAILURE);
		}
		i--;
	}
	if (a->size == 0)
		return (FAILURE);
	return (SUCCESS);
}
