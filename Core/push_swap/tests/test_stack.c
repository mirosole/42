#include "stack.h"
#include <stdio.h>

static int	failures;

#define CHECK(condition) do { \
	if (!(condition)) { \
		fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
		failures++; \
	} \
} while (0)

static void	test_init_and_empty(void)
{
	t_stack	stack;

	stack = init_stack();
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	CHECK(is_empty(&stack));
	pop(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	pop(NULL);
}

static void	test_push_and_peek(void)
{
	t_stack	stack;
	t_list	copy;
	int		first;
	int		second;

	stack = init_stack();
	first = 10;
	second = -20;
	push_element(&first, &stack);
	CHECK(stack.top != NULL);
	if (stack.top == NULL)
		return ;
	CHECK(stack.top->content == &first);
	CHECK(stack.size == 1);
	CHECK(!is_empty(&stack));
	push_element(&second, &stack);
	CHECK(stack.top != NULL);
	if (stack.top == NULL)
		return ;
	CHECK(stack.top->content == &second);
	CHECK(stack.top->next != NULL);
	if (stack.top->next != NULL)
		CHECK(stack.top->next->content == &first);
	CHECK(stack.size == 2);
	copy = peek(&stack);
	CHECK(copy.content == &second);
	CHECK(copy.next == stack.top->next);
	CHECK(stack.top->content == &second);
	CHECK(stack.size == 2);
	pop(&stack);
	pop(&stack);
}

static void	test_pop_order_and_size(void)
{
	t_stack	stack;
	int		first;
	int		second;

	stack = init_stack();
	first = 10;
	second = 20;
	push_element(&first, &stack);
	push_element(&second, &stack);
	if (stack.top == NULL || stack.top->next == NULL)
		return ;
	pop(&stack);
	CHECK(stack.top != NULL);
	if (stack.top != NULL)
		CHECK(stack.top->content == &first);
	CHECK(stack.size == 1);
	CHECK(!is_empty(&stack));
	pop(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	CHECK(is_empty(&stack));
	pop(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
}

static void	test_swap_empty_and_single(void)
{
	t_stack	stack;
	t_list	*only_node;
	int		value;

	stack = init_stack();
	swap(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	value = 42;
	push_element(&value, &stack);
	only_node = stack.top;
	swap(&stack);
	CHECK(stack.top == only_node);
	CHECK(only_node->next == NULL);
	CHECK(stack.size == 1);
	pop(&stack);
}

static void	test_swap_two_elements(void)
{
	t_stack	stack;
	t_list	*first_node;
	t_list	*second_node;
	int		first;
	int		second;

	stack = init_stack();
	first = 10;
	second = 20;
	push_element(&second, &stack);
	push_element(&first, &stack);
	first_node = stack.top;
	second_node = first_node->next;
	swap(&stack);
	CHECK(stack.top == second_node);
	CHECK(second_node->next == first_node);
	CHECK(first_node->next == NULL);
	CHECK(stack.size == 2);
	free(first_node);
	free(second_node);
}

static void	test_swap_three_elements(void)
{
	t_stack	stack;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;
	int		values[3];

	stack = init_stack();
	values[0] = 10;
	values[1] = 20;
	values[2] = 30;
	push_element(&values[2], &stack);
	push_element(&values[1], &stack);
	push_element(&values[0], &stack);
	first_node = stack.top;
	second_node = first_node->next;
	third_node = second_node->next;
	swap(&stack);
	CHECK(stack.top == second_node);
	CHECK(second_node->next == first_node);
	CHECK(first_node->next == third_node);
	CHECK(third_node->next == NULL);
	CHECK(stack.size == 3);
	free(first_node);
	free(second_node);
	free(third_node);
}

static void	test_rotate_empty_and_single(void)
{
	t_stack	stack;
	t_list	*only_node;
	int		value;

	stack = init_stack();
	rotate(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	value = 42;
	push_element(&value, &stack);
	only_node = stack.top;
	rotate(&stack);
	CHECK(stack.top == only_node);
	CHECK(stack.top->content == &value);
	CHECK(stack.top->next == NULL);
	CHECK(stack.size == 1);
	pop(&stack);
}

static void	test_rotate_three_elements(void)
{
	t_stack	stack;
	int		values[3];

	stack = init_stack();
	values[0] = 10;
	values[1] = 20;
	values[2] = 30;
	push_element(&values[2], &stack);
	push_element(&values[1], &stack);
	push_element(&values[0], &stack);
	rotate(&stack);
	CHECK(stack.size == 3);
	CHECK(stack.top != NULL);
	if (stack.top != NULL)
	{
		CHECK(stack.top->content == &values[1]);
		CHECK(stack.top->next != NULL);
		if (stack.top->next != NULL)
		{
			CHECK(stack.top->next->content == &values[2]);
			CHECK(stack.top->next->next != NULL);
			if (stack.top->next->next != NULL)
			{
				CHECK(stack.top->next->next->content == &values[0]);
				CHECK(stack.top->next->next->next == NULL);
			}
		}
	}
	free_stack(&stack);
}

static void	test_rotate_reverse_empty_and_single(void)
{
	t_stack	stack;
	t_list	*only_node;
	int		value;

	stack = init_stack();
	rotate_reverse(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	value = 42;
	push_element(&value, &stack);
	only_node = stack.top;
	rotate_reverse(&stack);
	CHECK(stack.top == only_node);
	CHECK(stack.top->content == &value);
	CHECK(stack.top->next == NULL);
	CHECK(stack.size == 1);
	pop(&stack);
}

static void	test_rotate_reverse_three_elements(void)
{
	t_stack	stack;
	int		values[3];

	stack = init_stack();
	values[0] = 10;
	values[1] = 20;
	values[2] = 30;
	push_element(&values[2], &stack);
	push_element(&values[1], &stack);
	push_element(&values[0], &stack);
	rotate_reverse(&stack);
	CHECK(stack.size == 3);
	CHECK(stack.top != NULL);
	if (stack.top != NULL)
	{
		CHECK(stack.top->content == &values[2]);
		CHECK(stack.top->next != NULL);
		if (stack.top->next != NULL)
		{
			CHECK(stack.top->next->content == &values[0]);
			CHECK(stack.top->next->next != NULL);
			if (stack.top->next->next != NULL)
			{
				CHECK(stack.top->next->next->content == &values[1]);
				CHECK(stack.top->next->next->next == NULL);
			}
		}
	}
	free_stack(&stack);
}

static void	test_push_to_empty_stack(void)
{
	t_stack	source;
	t_stack	destination;
	int		value;

	source = init_stack();
	destination = init_stack();
	value = 42;
	push_element(&value, &source);
	push(&source, &destination);
	CHECK(source.top == NULL);
	CHECK(source.size == 0);
	CHECK(destination.size == 1);
	CHECK(destination.top != NULL);
	if (destination.top != NULL)
	{
		CHECK(destination.top->content == &value);
		CHECK(destination.top->next == NULL);
	}
	pop(&source);
	pop(&destination);
}

static void	test_push_onto_populated_stack(void)
{
	t_stack	source;
	t_stack	destination;
	int		values[3];

	source = init_stack();
	destination = init_stack();
	values[0] = 10;
	values[1] = 20;
	values[2] = 30;
	push_element(&values[1], &source);
	push_element(&values[0], &source);
	push_element(&values[2], &destination);
	push(&source, &destination);
	CHECK(source.size == 1);
	CHECK(source.top != NULL);
	if (source.top != NULL)
		CHECK(source.top->content == &values[1]);
	CHECK(destination.size == 2);
	CHECK(destination.top != NULL);
	if (destination.top != NULL)
	{
		CHECK(destination.top->content == &values[0]);
		CHECK(destination.top->next != NULL);
		if (destination.top->next != NULL)
		{
			CHECK(destination.top->next->content == &values[2]);
			CHECK(destination.top->next->next == NULL);
		}
	}
	pop(&source);
	pop(&source);
	pop(&destination);
	pop(&destination);
}

static void	test_push_from_empty_stack(void)
{
	t_stack	source;
	t_stack	destination;
	t_list	*original_top;
	int		value;

	source = init_stack();
	destination = init_stack();
	value = 42;
	push_element(&value, &destination);
	original_top = destination.top;
	push(&source, &destination);
	CHECK(source.top == NULL);
	CHECK(source.size == 0);
	CHECK(destination.top == original_top);
	CHECK(destination.size == 1);
	pop(&destination);
}

static void	test_free_stack_with_elements(void)
{
	t_stack	stack;
	int		values[3];

	stack = init_stack();
	values[0] = 10;
	values[1] = 20;
	values[2] = 30;
	push_element(&values[0], &stack);
	push_element(&values[1], &stack);
	push_element(&values[2], &stack);
	free_stack(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	CHECK(is_empty(&stack));
	CHECK(values[0] == 10 && values[1] == 20 && values[2] == 30);
}

static void	test_free_stack_with_one_element(void)
{
	t_stack	stack;
	int		value;

	stack = init_stack();
	value = 42;
	push_element(&value, &stack);
	free_stack(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	CHECK(is_empty(&stack));
	CHECK(value == 42);
}

static void	test_free_empty_stack(void)
{
	t_stack	stack;

	stack = init_stack();
	free_stack(&stack);
	CHECK(stack.top == NULL);
	CHECK(stack.size == 0);
	CHECK(is_empty(&stack));
}

int	main(void)
{
	test_init_and_empty();
	test_push_and_peek();
	test_pop_order_and_size();
	test_swap_empty_and_single();
	test_swap_two_elements();
	test_swap_three_elements();
	test_rotate_empty_and_single();
	test_rotate_three_elements();
	test_rotate_reverse_empty_and_single();
	test_rotate_reverse_three_elements();
	test_push_to_empty_stack();
	test_push_onto_populated_stack();
	test_push_from_empty_stack();
	test_free_stack_with_elements();
	test_free_stack_with_one_element();
	test_free_empty_stack();
	if (failures != 0)
	{
		fprintf(stderr, "%d stack test(s) failed\n", failures);
		return (1);
	}
	puts("All stack tests passed");
	return (0);
}
