/* Tests for rotate_stack and prepare_b_for_push; no full sort is called. */
#include "stack.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

static size_t rb_calls;
static size_t rrb_calls;
static size_t cases;
static size_t failed;

/* GNU ld wrappers count calls while executing the real commands. */
void __real_rb(t_stack *s);
void __real_rrb(t_stack *s);

void __wrap_rb(t_stack *s)
{
	rb_calls++;
	__real_rb(s);
}

void __wrap_rrb(t_stack *s)
{
	rrb_calls++;
	__real_rrb(s);
}

static void reset_counts(void)
{
	rb_calls = 0;
	rrb_calls = 0;
}

static t_stack make_stack(int *values, size_t size)
{
	t_stack s;

	s = init_stack();
	while (size > 0)
		push_element(&values[--size], &s);
	return (s);
}

static void clear_stack(t_stack *s)
{
	while (s->top)
		pop(s);
}

/* Compare every value, the recorded size, and the list termination. */
static int matches(t_stack *s, int *values, size_t size)
{
	t_list *cur;
	size_t i;

	if (s->size != size)
		return (0);
	cur = s->top;
	i = 0;
	while (i < size)
	{
		if (!cur || !cur->content || *(int *)cur->content != values[i])
			return (0);
		cur = cur->next;
		i++;
	}
	return (cur == NULL);
}

static int shortest_commands(size_t pos, size_t size)
{
	if (size < 2 || pos == 0)
		return (rb_calls == 0 && rrb_calls == 0);
	if (pos <= size - pos)
		return (rb_calls == pos && rrb_calls == 0);
	return (rb_calls == 0 && rrb_calls == size - pos);
}

static void print_values(int *values, size_t size)
{
	size_t i;

	fprintf(stderr, "[");
	i = 0;
	while (i < size)
	{
		fprintf(stderr, "%s%d", i ? ", " : "", values[i]);
		i++;
	}
	fprintf(stderr, "]");
}

static void check_rotation(int *values, size_t size, size_t depth)
{
	t_stack s;
	int expected[8];
	size_t i;

	s = make_stack(values, size);
	i = 0;
	while (i < size)
	{
		expected[i] = values[(i + depth) % size];
		i++;
	}
	reset_counts();
	rotate_stack(&s, depth);
	cases++;
	if (!matches(&s, expected, size) || !shortest_commands(depth, size))
	{
		failed++;
		fprintf(stderr, "FAIL rotate_stack: size=%zu depth=%zu, rb=%zu rrb=%zu\n",
			size, depth, rb_calls, rrb_calls);
	}
	clear_stack(&s);
}

static void test_rotation(void)
{
	int values[] = {INT_MIN, 7, -4, INT_MAX, 0, 19, -30, 2};
	size_t size;
	size_t depth;

	check_rotation(NULL, 0, 0);
	size = 1;
	while (size <= sizeof(values) / sizeof(values[0]))
	{
		depth = 0;
		while (depth < size)
			check_rotation(values, size, depth++);
		size++;
	}
}

/* Independent oracle: successor is the largest existing value below x.
   If x is smaller than every value, its successor is the maximum. */
static size_t insertion_successor(int *values, size_t size, int x)
{
	size_t best;
	size_t maximum;
	size_t i;

	best = size;
	maximum = 0;
	i = 0;
	while (i < size)
	{
		if (values[i] > values[maximum])
			maximum = i;
		if (values[i] < x && (best == size || values[i] > values[best]))
			best = i;
		i++;
	}
	if (best == size)
		return (maximum);
	return (best);
}

/* Check circular order independently of production sorting helpers. */
static int cyclic_descending(t_stack *s)
{
	t_list *cur;
	t_list *next;
	size_t rises;
	size_t i;

	if (s->size < 2)
		return (1);
	cur = s->top;
	rises = 0;
	i = 0;
	while (cur && i < s->size)
	{
		next = cur->next;
		if (!next)
			next = s->top;
		if (*(int *)cur->content == *(int *)next->content)
			return (0);
		rises += (*(int *)cur->content < *(int *)next->content);
		cur = cur->next;
		i++;
	}
	return (!cur && i == s->size && rises == 1);
}

static void check_prepare(int *values, size_t size, int x)
{
	t_stack b;
	t_stack a;
	int expected[9];
	size_t pos;
	size_t i;
	int prepared;
	int commands;
	int pushed;

	b = make_stack(values, size);
	a = make_stack(&x, 1);
	pos = insertion_successor(values, size, x);
	expected[0] = x;
	i = 0;
	while (i < size)
	{
		expected[i + 1] = values[(i + pos) % size];
		i++;
	}
	reset_counts();
	prepare_b_for_push(&b, x);
	prepared = matches(&b, expected + 1, size) && matches(&a, &x, 1);
	commands = shortest_commands(pos, size);
	pb(&a, &b);
	pushed = matches(&b, expected, size + 1)
		&& matches(&a, NULL, 0) && cyclic_descending(&b);
	cases++;
	if (!prepared || !commands || !pushed)
	{
		failed++;
		if (failed <= 12)
		{
			fprintf(stderr, "FAIL prepare_b_for_push: B=");
			print_values(values, size);
			fprintf(stderr, " x=%d; expected B before pb=", x);
			print_values(expected + 1, size);
			fprintf(stderr, "; order=%s commands=%s after_pb=%s (rb=%zu rrb=%zu)\n",
				prepared ? "OK" : "FAIL", commands ? "OK" : "FAIL",
				pushed ? "OK" : "FAIL", rb_calls, rrb_calls);
		}
	}
	clear_stack(&a);
	clear_stack(&b);
}

static void test_prepare(void)
{
	int descending[] = {INT_MAX, 9, 7, 4, 1, -3, -9, INT_MIN};
	int candidates[] = {INT_MIN, -10, -5, -1, 0, 2, 6, 8, 10, INT_MAX};
	int values[8];
	size_t size;
	size_t shift;
	size_t i;
	size_t candidate;
	int duplicate;

	/* These named regressions illustrate forward and reverse insertion. */
	check_prepare((int[]){9, 7, 4, 1}, 4, 6);
	check_prepare((int[]){9, 7, 4, 1}, 4, 2);
	check_prepare((int[]){9, 7, 4, 1}, 4, 10);
	check_prepare((int[]){9, 7, 4, 1}, 4, 0);
	check_prepare((int[]){7, 4, 1, 9}, 4, 8);
	reset_counts();
	prepare_b_for_push(NULL, 42);
	cases++;
	if (rb_calls || rrb_calls)
		failed++;
	size = 0;
	while (size <= 8)
	{
		shift = 0;
		while (shift < size || (size == 0 && shift == 0))
		{
			i = 0;
			while (i < size)
			{
				values[i] = descending[(i + shift) % size];
				i++;
			}
			candidate = 0;
			while (candidate < sizeof(candidates) / sizeof(candidates[0]))
			{
				duplicate = 0;
				i = 0;
				while (i < size)
					duplicate |= (values[i++] == candidates[candidate]);
				if (!duplicate)
					check_prepare(values, size, candidates[candidate]);
				candidate++;
			}
			shift++;
		}
		size++;
	}
}

int main(int argc, char **argv)
{
	int run_rotate;
	int run_prepare;

	run_rotate = argc == 1 || (argc == 2 && strcmp(argv[1], "rotate") == 0);
	run_prepare = argc == 1 || (argc == 2 && strcmp(argv[1], "prepare") == 0);
	if (!run_rotate && !run_prepare)
		return (fprintf(stderr, "Usage: %s [rotate|prepare]\n", argv[0]), 2);
	if (run_rotate)
		test_rotation();
	if (run_prepare)
		test_prepare();
	printf("%zu/%zu cases passed (%zu failed)\n", cases - failed, cases, failed);
	return (failed != 0);
}
