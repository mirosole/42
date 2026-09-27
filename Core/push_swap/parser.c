#include "stack.h"

static int	set_strategy(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		config->strategy = STRATEGY_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		config->strategy = STRATEGY_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		config->strategy = STRATEGY_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		config->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	config->strategy_set = 1;
	return (1);
}

static int	parse_flag(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		if (config->bench)
			return (0);
		config->bench = 1;
		return (1);
	}
	if (config->strategy_set)
		return (0);
	return (set_strategy(arg, config));
}

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
				return (0);
		}
		else
		{
			if (!parse_int(argv[i], &number))
				return (0);
			if (has_duplicate(a, number) || !add_number(a, number))
				return (0);
		}
		i--;
	}
	if (a->size == 0)
		return (0);
	return (1);
}
