#include "stack.h"

static void	init_config(t_config *config)
{
	config->strategy = STRATEGY_ADAPTIVE;
	config->bench = 0;
	config->strategy_set = 0;
}

static int	run_adaptive(t_stack *a, t_stack *b, double disorder)
{
	if (disorder < 0.2)
		return (sort_simple(a, b));
	if (disorder < 0.5)
		return (sort_medium(a, b));
	return (sort_complex(a, b));
}

static int	run_sort(t_stack *a, t_stack *b,
		t_config *config, double disorder)
{
	if (config->strategy == STRATEGY_SIMPLE)
		return (sort_simple(a, b));
	if (config->strategy == STRATEGY_MEDIUM)
		return (sort_medium(a, b));
	if (config->strategy == STRATEGY_COMPLEX)
		return (sort_complex(a, b));
	return (run_adaptive(a, b, disorder));
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;
	double		disorder;

	if (argc == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	init_config(&config);
	if (!parse_arguments(argc, argv, &a, &config))
	{
		write(2, "Error\n", 6);
		free_parsed_stack(&a);
		return (1);
	}
	disorder = compute_disorder(&a);
	if (!run_sort(&a, &b, &config, disorder))
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