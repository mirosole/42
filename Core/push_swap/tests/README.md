# Stack helper tests

Run the basic stack tests:

```sh
make test
```

Build and run the sorting helper tests:

```sh
make test-sort-o2
```

While `stack_sort_O2.c` contains unused draft variables, use this temporary
command-line override. It keeps the warnings visible and does not change the
project's default compiler flags:

```sh
make test-sort-o2 CFLAGS='-Wall -Wextra -Werror -Wno-error=unused-variable'
```

After compilation, run either group independently:

```sh
./tests/test_sort_o2 rotate
./tests/test_sort_o2 prepare
```

A nonzero exit status means at least one case failed. Preparation failures print
the input, the inserted value, the expected stack before `pb`, and command counts.
The first 12 failures are printed; the summary counts all failures.

## Contracts covered

- `rotate_stack`: depth is a zero-based target position, `0 <= depth < size`.
  Empty stacks are tested with depth 0. Every valid depth for sizes 1 through 8
  is checked for exact resulting order, unchanged size, and shortest rotation.
  Ties prefer `rb`. NULL stacks and out-of-range depths are outside this test
  contract; passing these tests does not establish support for those inputs.
- `prepare_b_for_push`: B is cyclically descending and the new value is absent.
  Tests cover NULL, empty and singleton stacks, every cyclic orientation of
  stacks up to size 8, interior insertion, last-to-first insertion, new extrema,
  negative values, `INT_MIN`, and `INT_MAX`. Expected positions are calculated
  independently by finding the largest value below the new value, falling back
  to the maximum when necessary.
- Preparation must preserve B's existing values and size and use the shortest
  rotation. Each case then performs a real `pb` and checks the entire resulting
  sequence, cyclic descending order, and the emptied source stack.

GNU ld `--wrap` intercepts `rb` and `rrb` to count calls, then invokes the real
commands. This is test-only instrumentation and requires a compatible linker.
The helper tests do not call `sort_stack_O2` and do not test
command output formatting.

## Full sort

```sh
make test-sort-full
```

`tests/test_sort_full.c` calls `sort_stack_O2` with valid unique integers in A
and an empty B. It checks all values against an independently sorted copy,
A's size and list termination, and both B's size and top pointer. Cases include
empty and singleton inputs, sorted/reversed/cyclically shifted inputs, one
inversion, integer extremes, every permutation for sizes 0 through 7, and
sorted, reversed, and reproducibly shuffled inputs of sizes 10, 100, and 500.
There are 5,939 cases; each sort call has a five-second watchdog that terminates
the test process on a hang. The first 12 failures show input A, expected A,
final A and B, and separate result checks. Values run from top to bottom;
long lists are abbreviated after 20 values. The summary counts all failures.

The suite tests final stack contents, not stdout or operation-count limits.
It uses POSIX `alarm`/`SIGALRM` for the watchdog. Standard-library sorting is
used only by the test oracle, not by the production algorithm.

A failing test makes `make` return a nonzero status. Once compiled, rerun with
`./tests/test_sort_full` without rebuilding.
