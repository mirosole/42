NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I. -Ilibft

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_SRCS := $(wildcard $(LIBFT_DIR)/*.c)
HEADERS := push_swap.h $(LIBFT_DIR)/libft.h

SRCS := main.c \
	benchmark.c \
	parser.c \
	parse_number.c \
	parser_stack.c \
	stack.c \
	stack_operations.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	strategy.c \
	sort_small.c \
	sort_simple.c \
	sort_medium.c \
	sort_medium_chunks.c \
	sort_complex.c \
	merge_sort.c \
	rank.c \
	compute_disorder.c

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/Makefile
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	$(MAKE) all