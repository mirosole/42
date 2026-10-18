*This project has been created as part of the 42 curriculum by asomich, olmirosh.*

# push_swap

## Description

Push_swap is a C sorting project using two stacks and a restricted set of
operations. This repository implements the mandatory part of subject version
1.1, with Simple, Medium, Complex, and Adaptive sorting strategies.

The program receives distinct signed integers. The first number is initially
at the top of stack A, and stack B starts empty. It prints operations that leave
A sorted in ascending order, with its smallest value on top and B empty.
The goal is to keep the generated Push_swap operation sequence as small as
possible while respecting the required complexity class of each strategy.

| Operations | Action |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the top two elements of A, B, or both. |
| `pa`, `pb` | Move the top element from B to A, or from A to B. |
| `ra`, `rb`, `rr` | Move the top element to the bottom of A, B, or both. |
| `rra`, `rrb`, `rrr` | Move the bottom element to the top of A, B, or both. |

Adaptive is the default strategy. The optional `--bench` mode reports the
initial disorder, selected strategy, theoretical complexity, and operation
counts to stderr while the operation stream remains on stdout.

## Instructions

### Compilation with Make

Run commands from the project root. You need a C compiler available as `cc`,
GNU Make, and `ar` for building the static library.

```sh
make
```

The Makefile compiles the project sources, builds `libft/libft.a` through
libft's own Makefile, and links everything into the `push_swap` executable.
The libft sources, header, and Makefile must remain in `libft/`.

| Command | Effect |
| --- | --- |
| `make` or `make all` | Build `push_swap`. |
| `make push_swap` | Build the executable by its target name. |
| `make clean` | Remove project and libft object files; keep the executable and library. |
| `make fclean` | Remove object files, `push_swap`, and `libft/libft.a`. |
| `make re` | Clean all build outputs and rebuild. |

Compilation uses `cc` with `-Wall -Wextra -Werror`. Project headers are found
through `-I.` and `-Ilibft`.

Running `make` again without source changes must not unnecessarily relink the
program.

For a debug build:

```sh
make re CFLAGS='-Wall -Wextra -Werror -g'
```

### Compilation from the command line

The normal and recommended way to build the project is `make`. If a direct
command-line build is needed, first build libft and then compile the current
source list:

```sh
make -C libft
cc -Wall -Wextra -Werror -I. -Ilibft \
    main.c benchmark.c parser.c parse_number.c parser_stack.c \
    stack.c stack_operations.c push.c swap.c rotate.c reverse_rotate.c \
    strategy.c sort_small.c sort_simple.c sort_medium.c sort_medium_chunks.c \
    sort_complex.c merge_sort.c rank.c compute_disorder.c \
    libft/libft.a -o push_swap
```

### Usage

```sh
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] integers...
```

Examples:

```sh
./push_swap 4 67 3 -8 23
./push_swap --simple 3 2 1
./push_swap --medium 4 67 3 -8 23
./push_swap --complex 4 67 3 -8 23
./push_swap --adaptive --bench 4 67 3 -8 23
```

Each integer must currently be passed as a separate argument. A quoted list
such as `./push_swap "3 2 1"` is not supported by this parser. Values must fit
in a signed 32-bit `int`, and duplicates are rejected. Choose at most one
strategy selector and use `--bench` at most once.

With no arguments the program exits silently. Already sorted input produces no
operations. Invalid input prints exactly `Error\n` to stderr.

### Benchmark output

`--bench` reports:

- initial disorder as a percentage with two decimal places;
- selected strategy and its theoretical operation complexity;
- total operation count;
- count of each operation type.

The benchmark goes to stderr, so stdout can still be piped into a checker.

```sh
./push_swap --bench 4 67 3 -8 23 > /dev/null
./push_swap 4 67 3 -8 23 | wc -l
```

## Algorithms and design

The complexity classes below refer to the number of emitted Push_swap
operations, as required by the project subject. Helper CPU work such as
computing disorder, ranking, merge sorting the rank array, or scanning linked
lists does not itself emit Push_swap operations.

### Small inputs: dedicated strategy for 5 elements or fewer

`sort_small.c` is used as a common constant-size base case for all strategy
selectors when stack A contains at most five elements.

- For two elements, `sa` is used only if the pair is reversed.
- For three elements, `sort_three` chooses a direct combination of `sa`, `ra`,
  and `rra` based on the current ordering.
- For four or five elements, the current minimum is moved to the top using the
  shorter direction (`ra` or `rra`) and pushed to B with `pb` until three
  elements remain in A.
- The remaining three elements are sorted directly, then the saved minima are
  returned from B with `pa`.

This small-input handler exists to keep operation counts low for the exhaustive
3- and 5-element cases. Because it is only used for a fixed maximum size, it
does not change the asymptotic complexity of Simple, Medium, or Complex for
growing input sizes.

### Ranking preprocessing

`rank_stack` replaces each value with its position in sorted order from `0` to
`n - 1`. For example, `40 -8 12` becomes `2 0 1`.

`rank.c` copies values into an array, sorts the array using `merge_sort.c`, and
uses binary search to find each value's rank. Ranking makes chunk and radix
logic independent of the original integer range, including negative values and
integer limits. It emits no Push_swap operations and uses O(n) auxiliary
storage.

### Simple: fixed-size rank chunks — O(n²)

`sort_simple.c` implements the Simple strategy with a fixed chunk size of 20.

1. Rank all values in A from `0` to `n - 1`.
2. Divide the rank range into consecutive chunks of at most 20 ranks.
3. For the current chunk, scan A: matching ranks are pushed to B with `pb`,
   while non-matching values are rotated with `ra`.
4. Continue until every chunk has been transferred to B.
5. Repeatedly find the maximum rank in B, rotate B by the shorter direction
   (`rb` or `rrb`), and return that maximum to A with `pa`.

Returning maxima first builds A in ascending order because every new value is
placed above larger values already returned to A.

The chunk size is a constant. Therefore the number of chunks grows linearly
with n: approximately `n / 20`, which is O(n). A chunk scan can require O(n)
Push_swap operations, giving an O(n²) upper bound for distribution. Returning
n maxima can also require up to O(n) rotations per element in the worst case,
so the complete Simple strategy remains O(n²) in the Push_swap operation model.
Ranking uses O(n) auxiliary storage.

### Medium: square-root rank chunks — O(n√n)

`sort_medium.c` and `sort_medium_chunks.c` use the same broad distribution and
retrieval idea as Simple, but the chunk size depends on the input size instead
of being constant.

1. Rank all values.
2. Choose a chunk size approximately equal to `√n`.
3. Process consecutive rank ranges from low to high, pushing matching values to
   B and rotating non-matching values in A.
4. Repeatedly retrieve B's maximum using the shorter rotation direction and
   push it back to A.

There are approximately O(√n) chunks, with scans bounded by O(n) Push_swap
operations per chunk, giving the required O(n√n) operation bound. Ranking uses
O(n) auxiliary storage.

The key distinction from Simple is therefore the chunk size:

- Simple: constant chunk size `20` -> O(n²).
- Medium: chunk size proportional to `√n` -> O(n√n).

### Complex: binary LSD radix sort — O(n log n)

`sort_complex.c` uses the ranked values and processes one bit at a time,
starting with the least significant bit.

1. Inspect every value in A for the current bit.
2. If the bit is zero, push the value to B with `pb`; otherwise rotate A with
   `ra`.
3. Push all values from B back to A with `pa`.
4. Repeat for the next bit until every bit needed for rank `n - 1` has been
   processed.

Each bit pass is a stable binary partition. Ranked values need O(log n) bits,
and each pass emits O(n) operations, giving O(n log n) Push_swap operations.
Ranking uses O(n) auxiliary storage.

### Adaptive: strategy selection by initial disorder

Before any moves, `compute_disorder.c` measures the fraction of inverted pairs:

```text
disorder = inversions / (n × (n - 1) / 2)
```

`strategy.c` then selects the required regime:

| Initial disorder | Selected strategy | Operation bound |
| --- | --- | --- |
| `disorder < 0.2` | Simple | O(n²) |
| `0.2 <= disorder < 0.5` | Medium | O(n√n) |
| `disorder >= 0.5` | Complex | O(n log n) |

There is no size-based fallback that silently replaces one adaptive regime
with another. For inputs of five elements or fewer, the shared `sort_small`
base case is used after strategy selection because it is a fixed-size
optimization and does not affect the asymptotic regime.

If disorder is zero, the input is already sorted and no sorting operations are
emitted.

## Testing

### Recommended tester: ft_ps_tester

The project was tested with
[ft_ps_tester](https://github.com/italoalmeida0/ft_ps_tester), a tester designed
for the four-strategy version of Push_swap. It checks the strategy flags,
controlled disorder levels, performance thresholds, basic edge cases,
benchmark output, and memory errors when Valgrind is available.

#### Install with pip

```sh
python3 -m pip install --user ft_ps_tester
```

If the shell cannot find `ft_ps_tester` after a user-local installation:

```sh
export PATH="$HOME/.local/bin:$PATH"
```

For Zsh, the path can be made persistent with:

```sh
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
```

#### Install from GitHub instead

```sh
git clone https://github.com/italoalmeida0/ft_ps_tester.git
cd ft_ps_tester
python3 -m pip install --user .
cd ..
```

#### Run tests

Build `push_swap` first:

```sh
make
```

Run the complete suite:

```sh
ft_ps_tester ./push_swap
```

Run only basic and edge-case checks:

```sh
ft_ps_tester --basic ./push_swap
```

Test an individual strategy on 100 or 500 values:

```sh
ft_ps_tester ./push_swap 100 simple
ft_ps_tester ./push_swap 100 medium
ft_ps_tester ./push_swap 100 complex
ft_ps_tester ./push_swap 100 adaptive

ft_ps_tester ./push_swap 500 simple
ft_ps_tester ./push_swap 500 medium
ft_ps_tester ./push_swap 500 complex
ft_ps_tester ./push_swap 500 adaptive
```

If the executable command is not on `PATH`, the module form can be used:

```sh
python3 -m ft_ps_tester ./push_swap
```

For failing random cases, generate replayable reports with:

```sh
ft_ps_tester --reports ./push_swap
```

The external tester is a development aid; the project subject and official
peer-evaluation requirements remain authoritative.

### Manual error and memory checks

```sh
./push_swap
./push_swap 1 2 3
./push_swap 1 1
./push_swap 2147483648
./push_swap 1 two 3
./push_swap --simple --complex 3 2 1
```

The first two commands should produce no output. Invalid inputs should print
`Error` to stderr.

If Valgrind is installed:

```sh
make re CFLAGS='-Wall -Wextra -Werror -g'
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 -1 2
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 3
```

## Contributions

The project contributions are divided as follows:

- **asomich (Andrey Somich):** stack primitives and initial stack tests,
  disorder calculation, adaptive dispatch, integration of sorting strategies,
  complex sorting, and memory-leak fixes.
- **olmirosh (Oleksii Miroshnichenko):** Simple and Medium sorting algorithms,
  small-input sorting integration, benchmark reporting, and benchmark tests.

Both learners must understand the complete implementation and be able to
explain any part of the code during evaluation.

## Resources

- [Project subject, version 1.1](push_swap.pdf): operations, required strategies,
  complexity model, and evaluation requirements.
- [Stack Overflow](https://stackoverflow.com/): programming questions and discussions.
- [GeeksforGeeks](https://www.geeksforgeeks.org/): algorithm and data-structure explanations.
- [METANIT C tutorial](https://metanit.com/c/tutorial/): C language study materials.
- [ChatGPT](https://chatgpt.com/): AI assistance during development and documentation.
- [ft_ps_tester](https://github.com/italoalmeida0/ft_ps_tester): external testing tool used during development.

### Use of AI

AI was used to help review code style, improve documentation, prepare test
commands, analyze operation counts, and investigate implementation issues.
AI-generated suggestions were reviewed and tested by the authors, who remain
responsible for understanding and defending the complete implementation.