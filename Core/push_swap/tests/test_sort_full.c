/* Full-sort contract: valid A, empty B -> ascending A, empty B. */
#include "stack.h"
#include <limits.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 500

static size_t cases;
static size_t failures;

static void timed_out(int signal_number)
{
	static const char message[] = "FAIL sort_stack_O2: case exceeded 5 seconds\n";

	(void)signal_number;
	write(STDERR_FILENO, message, sizeof(message) - 1);
	_exit(1);
}

static int compare_ints(const void *left, const void *right)
{
	int a;
	int b;

	a = *(const int *)left;
	b = *(const int *)right;
	return ((a > b) - (a < b));
}

static int matches(t_stack *a, int *expected, size_t size)
{
	t_list *cur;
	size_t i;

	if (a->size != size)
		return (0);
	cur = a->top;
	i = 0;
	while (i < size)
	{
		if (!cur || !cur->content || *(int *)cur->content != expected[i])
			return (0);
		cur = cur->next;
		i++;
	}
	return (cur == NULL);
}

static void print_values(int *values, size_t size)
{
	size_t i;

	fprintf(stderr, "[");
	i = 0;
	while (i < size && i < 20)
	{
		fprintf(stderr, "%s%d", i ? ", " : "", values[i]);
		i++;
	}
	fprintf(stderr, "%s]", size > 20 ? ", ..." : "");
}

static void print_stack(t_stack *s)
{
	t_list *cur;
	size_t i;

	fprintf(stderr, "[");
	cur = s->top;
	i = 0;
	while (cur && i < 20)
	{
		if (i > 0)
			fprintf(stderr, ", ");
		if (cur->content)
			fprintf(stderr, "%d", *(int *)cur->content);
		else
			fprintf(stderr, "NULL");
		cur = cur->next;
		i++;
	}
	fprintf(stderr, "%s] (size=%zu)", cur ? ", ..." : "", s->size);
}

static void print_case(const char *name, int *input, int *expected,
		size_t size, t_stack *a, t_stack *b)
{
	fprintf(stderr, "\nFAIL #%zu: %s (n=%zu)\n", cases, name, size);
	fprintf(stderr, "  Input A:    ");
	print_values(input, size);
	fprintf(stderr, "\n  Expected A: ");
	print_values(expected, size);
	fprintf(stderr, "\n  Final A:    ");
	print_stack(a);
	fprintf(stderr, "\n  Final B:    ");
	print_stack(b);
	fprintf(stderr, "\n  Checks:     A=%s, B empty=%s\n",
		matches(a, expected, size) ? "OK" : "FAIL",
		!b->top && b->size == 0 ? "OK" : "FAIL");
}

static void check_sort(const char *name, int *input, size_t size)
{
	t_stack a;
	t_stack b;
	int payload[MAX_SIZE];
	int expected[MAX_SIZE];
	size_t i;

	a = init_stack();
	b = init_stack();
	i = 0;
	while (i < size)
	{
		payload[i] = input[i];
		expected[i] = input[i];
		i++;
	}
	qsort(expected, size, sizeof(*expected), compare_ints);
	while (i > 0)
		push_element(&payload[--i], &a);
	alarm(5);
	sort_stack_O2(&a, &b);
	alarm(0);
	cases++;
	if (!matches(&a, expected, size) || b.top != NULL || b.size != 0)
	{
		failures++;
		if (failures <= 12)
			print_case(name, input, expected, size, &a, &b);
	}
	/* Keep cleanup under the watchdog too in case a bug creates a cycle. */
	alarm(5);
	while (a.top)
		pop(&a);
	while (b.top)
		pop(&b);
	alarm(0);
}

static void swap_values(int *a, int *b)
{
	int temporary;

	temporary = *a;
	*a = *b;
	*b = temporary;
}

static void permutations(int *values, size_t size, size_t pos)
{
	size_t i;

	if (pos == size)
	{
		check_sort("exhaustive permutation", values, size);
		return ;
	}
	i = pos;
	while (i < size)
	{
		swap_values(&values[pos], &values[i]);
		permutations(values, size, pos + 1);
		swap_values(&values[pos], &values[i]);
		i++;
	}
}

static void test_small_inputs(void)
{
	int values[] = {-9, -3, -1, 0, 2, 7, 11};
	size_t size;

	check_sort("empty", NULL, 0);
	check_sort("singleton", (int[]){42}, 1);
	check_sort("sorted pair", (int[]){1, 2}, 2);
	check_sort("reversed pair", (int[]){2, 1}, 2);
	check_sort("sorted", (int[]){-8, -2, 0, 4, 10}, 5);
	check_sort("reversed", (int[]){10, 4, 0, -2, -8}, 5);
	check_sort("cyclic shift", (int[]){0, 4, 10, -8, -2}, 5);
	check_sort("one inversion", (int[]){-8, 0, -2, 4, 10}, 5);
	check_sort("int extremes", (int[]){INT_MAX, 0, INT_MIN, -1, 1}, 5);
	check_sort("extreme pair", (int[]){INT_MAX, INT_MIN}, 2);
	size = 0;
	while (size <= sizeof(values) / sizeof(values[0]))
		permutations(values, size++, 0);
}

static uint32_t next_random(uint32_t *state)
{
	*state = *state * UINT32_C(1664525) + UINT32_C(1013904223);
	return (*state);
}

static void test_large_inputs(void)
{
	const size_t sizes[] = {10, 100, 500};
	int values[MAX_SIZE];
	uint32_t state;
	size_t group;
	size_t trial;
	size_t i;
	size_t size;

	state = UINT32_C(42);
	group = 0;
	while (group < sizeof(sizes) / sizeof(sizes[0]))
	{
		size = sizes[group++];
		i = 0;
		while (i < size)
		{
			values[i] = (int)i * 2 - (int)size;
			i++;
		}
		check_sort("large sorted", values, size);
		i = 0;
		while (i < size / 2)
		{
			swap_values(&values[i], &values[size - i - 1]);
			i++;
		}
		check_sort("large reversed", values, size);
		trial = 0;
		while (trial++ < 3)
		{
			i = size;
			while (i > 1)
			{
				swap_values(&values[i - 1], &values[next_random(&state) % i]);
				i--;
			}
			check_sort("seeded shuffle", values, size);
		}
	}
}

int main(void)
{
	if (signal(SIGALRM, timed_out) == SIG_ERR)
		return (perror("signal"), 2);
	fprintf(stderr, "Stack values are shown top -> bottom (first 20 values).\n");
	test_small_inputs();
	test_large_inputs();
	if (failures > 12)
		fprintf(stderr, "\n%zu additional failure details omitted.\n", failures - 12);
	fprintf(stderr, "\nFull sort: %zu/%zu cases passed (%zu failed)\n",
		cases - failures, cases, failures);
	return (failures != 0);
}
