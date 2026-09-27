#include "stack.h"

int	has_duplicate(t_stack *a, int number)
{
	t_list	*current;

	current = a->top;
	while (current)
	{
		if (*(int *)current->content == number)
			return (1);
		current = current->next;
	}
	return (0);
}

int	add_number(t_stack *a, int number)
{
	int		*value;
	t_list	*node;

	value = malloc(sizeof(int));
	if (!value)
		return (0);
	*value = number;
	node = ft_lstnew(value);
	if (!node)
	{
		free(value);
		return (0);
	}
	node->next = a->top;
	a->top = node;
	a->size++;
	return (1);
}
