#include "stack.h"

void	free_parsed_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
