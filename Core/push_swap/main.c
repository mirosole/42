#include "stack.h"

static void	init_config(t_config *config)
{
	config->strategy = STRATEGY_ADAPTIVE;
	config->bench = 0;
	config->strategy_set = 0;
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	if (argc == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	init_config(&config);
	if (!parse_arguments(argc, argv, &a, &config))
	{
		write(2, "Error\n", 6);
		free_parsed_stack(&a);
		free_parsed_stack(&b);
		return (1);
	}
	if (!sort_simple(&a, &b))
	{
		write(2, "Error\n", 6);
		free_parsed_stack(&a);
		free_parsed_stack(&b);
		return (1);
	}
	free_parsed_stack(&a);
	free_parsed_stack(&b);
	return (0);
}