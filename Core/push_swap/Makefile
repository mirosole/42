NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

PRINTF_DIR	:= ft_printf
PRINTF		:= $(PRINTF_DIR)/libftprintf.a

INCLUDES	:= -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

SRCS		:= $(wildcard *.c)
OBJS		:= $(SRCS:.c=.o)

TEST_BIN		:= tests/test_stack
SORT_TEST_BIN		:= tests/test_sort_o2
FULL_SORT_TEST_BIN	:= tests/test_sort_full

.PHONY: all clean fclean re test test-sort-o2 test-sort-full

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(TEST_BIN)
	rm -f $(SORT_TEST_BIN)
	rm -f $(FULL_SORT_TEST_BIN)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all