#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	result(int mine, int real)
{
	printf("\nreturn ft_printf = %d\n", mine);
	printf("return printf    = %d\n", real);
	if (mine == real)
		printf("RETURN: OK\n");
	else
		printf("RETURN: FAIL\n");
	printf("============================================\n\n");
}

static void	test_text(void)
{
	int	mine;
	int	real;

	printf("========== TEXT ==========\n");

	printf("printf:    ");
	real = printf("Hello world!\n");

	printf("ft_printf: ");
	mine = ft_printf("Hello world!\n");

	result(mine, real);

	printf("========== EMPTY ==========\n");

    printf("printf:    ");
    real = printf("%s", "");

    printf("\nft_printf: ");
    mine = ft_printf("");

	printf("\n");
	result(mine, real);
}

static void	test_char(void)
{
	int	mine;
	int	real;

	printf("========== CHAR %%c ==========\n");

	printf("printf:    ");
	real = printf("[%c] [%c] [%c] [%c]\n",
			'A', '0', ' ', '\n');

	printf("ft_printf: ");
	mine = ft_printf("[%c] [%c] [%c] [%c]\n",
			'A', '0', ' ', '\n');

	result(mine, real);
}

static void	test_string(void)
{
	int	mine;
	int	real;

	printf("========== STRING %%s ==========\n");

	printf("printf:    ");
	real = printf("[%s] [%s] [%s]\n",
			"hello", "", "42 Prague");

	printf("ft_printf: ");
	mine = ft_printf("[%s] [%s] [%s]\n",
			"hello", "", "42 Prague");

	result(mine, real);

	printf("Extra NULL test for ft_printf only:\n");
	ft_printf("[%s]\n", NULL);
	printf("============================================\n\n");
}

static void	test_decimal(void)
{
	int	mine;
	int	real;

	printf("========== DECIMAL %%d ==========\n");

	printf("printf:    ");
	real = printf("[%d] [%d] [%d] [%d] [%d]\n",
			0, 1, -1, INT_MAX, INT_MIN);

	printf("ft_printf: ");
	mine = ft_printf("[%d] [%d] [%d] [%d] [%d]\n",
			0, 1, -1, INT_MAX, INT_MIN);

	result(mine, real);
}

static void	test_integer(void)
{
	int	mine;
	int	real;

	printf("========== INTEGER %%i ==========\n");

	printf("printf:    ");
	real = printf("[%i] [%i] [%i] [%i] [%i]\n",
			0, 42, -42, INT_MAX, INT_MIN);

	printf("ft_printf: ");
	mine = ft_printf("[%i] [%i] [%i] [%i] [%i]\n",
			0, 42, -42, INT_MAX, INT_MIN);

	result(mine, real);
}

static void	test_unsigned(void)
{
	int	mine;
	int	real;

	printf("========== UNSIGNED %%u ==========\n");

	printf("printf:    ");
	real = printf("[%u] [%u] [%u] [%u]\n",
			0u, 1u, 42u, UINT_MAX);

	printf("ft_printf: ");
	mine = ft_printf("[%u] [%u] [%u] [%u]\n",
			0u, 1u, 42u, UINT_MAX);

	result(mine, real);
}

static void	test_hex_lower(void)
{
	int	mine;
	int	real;

	printf("========== HEX %%x ==========\n");

	printf("printf:    ");
	real = printf("[%x] [%x] [%x] [%x] [%x] [%x]\n",
			0u, 9u, 10u, 15u, 16u, UINT_MAX);

	printf("ft_printf: ");
	mine = ft_printf("[%x] [%x] [%x] [%x] [%x] [%x]\n",
			0u, 9u, 10u, 15u, 16u, UINT_MAX);

	result(mine, real);
}

static void	test_hex_upper(void)
{
	int	mine;
	int	real;

	printf("========== HEX %%X ==========\n");

	printf("printf:    ");
	real = printf("[%X] [%X] [%X] [%X] [%X] [%X]\n",
			0u, 9u, 10u, 15u, 16u, UINT_MAX);

	printf("ft_printf: ");
	mine = ft_printf("[%X] [%X] [%X] [%X] [%X] [%X]\n",
			0u, 9u, 10u, 15u, 16u, UINT_MAX);

	result(mine, real);
}

static void	test_pointer(void)
{
	int		mine;
	int		real;
	int		number;
	char	c;

	number = 42;
	c = 'A';

	printf("========== POINTER %%p ==========\n");

	printf("printf:    ");
	real = printf("[%p] [%p]\n",
			(void *)&number, (void *)&c);

	printf("ft_printf: ");
	mine = ft_printf("[%p] [%p]\n",
			(void *)&number, (void *)&c);

	result(mine, real);

	printf("Extra NULL pointer test:\n");
	ft_printf("[%p]\n", NULL);
	printf("============================================\n\n");
}

static void	test_percent(void)
{
	int	mine;
	int	real;

	printf("========== PERCENT %%%% ==========\n");

	printf("printf:    ");
	real = printf("[%%] [100%%] [%%%%]\n");

	printf("ft_printf: ");
	mine = ft_printf("[%%] [100%%] [%%%%]\n");

	result(mine, real);
}

static void	test_mixed(void)
{
	int	mine;
	int	real;
	int	x;

	x = 123;

	printf("========== MIXED ==========\n");

	printf("printf:    ");
	real = printf(
			"%c | %s | %d | %i | %u | %x | %X | %p | %%\n",
			'A',
			"hello",
			-42,
			INT_MIN,
			UINT_MAX,
			255u,
			255u,
			(void *)&x);

	printf("ft_printf: ");
	mine = ft_printf(
			"%c | %s | %d | %i | %u | %x | %X | %p | %%\n",
			'A',
			"hello",
			-42,
			INT_MIN,
			UINT_MAX,
			255u,
			255u,
			(void *)&x);

	result(mine, real);
}

static void	test_many(void)
{
	int	mine;
	int	real;

	printf("========== MANY CONVERSIONS ==========\n");

	printf("printf:    ");
	real = printf("%d%d%d%d%d %x%x%x %c%c%c %s%s %%\n",
			1, 22, 333, -4, 0,
			10u, 255u, UINT_MAX,
			'A', 'B', 'C',
			"hello", "world");

	printf("ft_printf: ");
	mine = ft_printf("%d%d%d%d%d %x%x%x %c%c%c %s%s %%\n",
			1, 22, 333, -4, 0,
			10u, 255u, UINT_MAX,
			'A', 'B', 'C',
			"hello", "world");

	result(mine, real);
}

int	main(void)
{
	test_text();
	test_char();
	test_string();
	test_decimal();
	test_integer();
	test_unsigned();
	test_hex_lower();
	test_hex_upper();
	test_pointer();
	test_percent();
	test_mixed();
	test_many();
	return (0);
}