#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

static int	g_passed;
static int	g_failed;

static void	check(const char *name, int condition)
{
	if (condition)
	{
		printf("[PASS] %s\n", name);
		g_passed++;
	}
	else
	{
		printf("[FAIL] %s\n", name);
		g_failed++;
	}
}

/* ========================================================= */
/*                       IS FUNCTIONS                        */
/* ========================================================= */

static void	test_isalpha(void)
{
	printf("\n========== ISALPHA ==========\n");

	check("A", ft_isalpha('A') == 1);
	check("Z", ft_isalpha('Z') == 1);
	check("a", ft_isalpha('a') == 1);
	check("z", ft_isalpha('z') == 1);
	check("1", ft_isalpha('1') == 0);
	check("space", ft_isalpha(' ') == 0);
	check("@", ft_isalpha('@') == 0);
}

static void	test_isdigit(void)
{
	printf("\n========== ISDIGIT ==========\n");

	check("0", ft_isdigit('0') == 1);
	check("5", ft_isdigit('5') == 1);
	check("9", ft_isdigit('9') == 1);
	check("a", ft_isdigit('a') == 0);
	check("/", ft_isdigit('/') == 0);
	check(":", ft_isdigit(':') == 0);
}

static void	test_isalnum(void)
{
	printf("\n========== ISALNUM ==========\n");

	check("A", ft_isalnum('A') == 1);
	check("z", ft_isalnum('z') == 1);
	check("0", ft_isalnum('0') == 1);
	check("9", ft_isalnum('9') == 1);
	check("space", ft_isalnum(' ') == 0);
	check("@", ft_isalnum('@') == 0);
}

static void	test_isascii(void)
{
	printf("\n========== ISASCII ==========\n");

	check("0", ft_isascii(0) == 1);
	check("65", ft_isascii(65) == 1);
	check("127", ft_isascii(127) == 1);
	check("128", ft_isascii(128) == 0);
	check("-1", ft_isascii(-1) == 0);
	check("255", ft_isascii(255) == 0);
}

static void	test_isprint(void)
{
	printf("\n========== ISPRINT ==========\n");

	check("space 32", ft_isprint(32) == 1);
	check("A", ft_isprint('A') == 1);
	check("~ 126", ft_isprint(126) == 1);
	check("31", ft_isprint(31) == 0);
	check("127", ft_isprint(127) == 0);
	check("newline", ft_isprint('\n') == 0);
}

/* ========================================================= */
/*                         STRLEN                            */
/* ========================================================= */

static void	test_strlen(void)
{
	printf("\n========== STRLEN ==========\n");

	check("Hello", ft_strlen("Hello") == 5);
	check("empty", ft_strlen("") == 0);
	check("one char", ft_strlen("A") == 1);
	check("spaces", ft_strlen("   ") == 3);
	check("Hello World", ft_strlen("Hello World") == 11);
	check("numbers", ft_strlen("123456789") == 9);
}

/* ========================================================= */
/*                         MEMSET                            */
/* ========================================================= */

static void	test_memset(void)
{
	char	str1[10] = "abcdef";
	char	str2[10] = "abcdef";
	char	str3[10] = "abcdef";

	printf("\n========== MEMSET ==========\n");

	ft_memset(str1, 'X', 3);
	check("first 3 bytes", strcmp(str1, "XXXdef") == 0);

	ft_memset(str2, 'A', 0);
	check("zero bytes", strcmp(str2, "abcdef") == 0);

	ft_memset(str3, 'Z', 6);
	check("all chars", strcmp(str3, "ZZZZZZ") == 0);
}

/* ========================================================= */
/*                          BZERO                            */
/* ========================================================= */

static void	test_bzero(void)
{
	char	str1[6] = "hello";
	char	str2[6] = "hello";

	printf("\n========== BZERO ==========\n");

	ft_bzero(str1, 2);
	check("zero first byte", str1[0] == '\0');
	check("zero second byte", str1[1] == '\0');
	check("third unchanged", str1[2] == 'l');

	ft_bzero(str2, 0);
	check("zero length", strcmp(str2, "hello") == 0);
}

/* ========================================================= */
/*                         MEMCPY                            */
/* ========================================================= */

static void	test_memcpy(void)
{
	char	src[] = "Hello";
	char	dst[10];
	char	dst2[10] = "ABC";

	printf("\n========== MEMCPY ==========\n");

	ft_memcpy(dst, src, 6);
	check("copy string", strcmp(dst, "Hello") == 0);

	ft_memcpy(dst2, "XYZ", 3);
	check("copy 3 bytes", memcmp(dst2, "XYZ", 3) == 0);

	ft_memcpy(dst2, src, 0);
	check("copy zero bytes", memcmp(dst2, "XYZ", 3) == 0);
}

/* ========================================================= */
/*                        MEMMOVE                            */
/* ========================================================= */

static void	test_memmove(void)
{
	char	str1[20] = "123456789";
	char	str2[20] = "123456789";
	char	str3[20] = "abcdef";

	printf("\n========== MEMMOVE ==========\n");

	ft_memmove(str1 + 2, str1, 5);
	check("overlap right", strcmp(str1, "121234589") == 0);

	ft_memmove(str2, str2 + 2, 5);
	check("overlap left", memcmp(str2, "345676789", 9) == 0);

	ft_memmove(str3, str3, 6);
	check("same pointer", strcmp(str3, "abcdef") == 0);
}

/* ========================================================= */
/*                        STRLCPY                            */
/* ========================================================= */

static void	test_strlcpy(void)
{
	char	dst1[20];
	char	dst2[5];
	char	dst3[10] = "ABC";
	size_t	result;

	printf("\n========== STRLCPY ==========\n");

	result = ft_strlcpy(dst1, "Hello", sizeof(dst1));
	check("normal result", result == 5);
	check("normal copy", strcmp(dst1, "Hello") == 0);

	result = ft_strlcpy(dst2, "Hello World", sizeof(dst2));
	check("small buffer result", result == 11);
	check("small buffer content", strcmp(dst2, "Hell") == 0);

	result = ft_strlcpy(dst3, "XYZ", 0);
	check("size zero result", result == 3);
	check("size zero unchanged", strcmp(dst3, "ABC") == 0);
}

/* ========================================================= */
/*                        STRLCAT                            */
/* ========================================================= */

static void	test_strlcat(void)
{
	char	dst1[20] = "Hello ";
	char	dst2[8] = "Hi";
	char	dst3[10] = "ABC";
	size_t	result;

	printf("\n========== STRLCAT ==========\n");

	result = ft_strlcat(dst1, "World", sizeof(dst1));
	check("normal content", strcmp(dst1, "Hello World") == 0);
	check("normal result", result == 11);

	result = ft_strlcat(dst2, "123456", sizeof(dst2));
	check("limited content", strcmp(dst2, "Hi12345") == 0);
	check("limited result", result == 8);

	result = ft_strlcat(dst3, "Hello", 0);
	check("size zero", result == 5);
	check("size zero unchanged", strcmp(dst3, "ABC") == 0);
}

/* ========================================================= */
/*                    TOUPPER / TOLOWER                      */
/* ========================================================= */

static void	test_case_conversion(void)
{
	printf("\n========== TOUPPER ==========\n");

	check("a -> A", ft_toupper('a') == 'A');
	check("z -> Z", ft_toupper('z') == 'Z');
	check("A unchanged", ft_toupper('A') == 'A');
	check("1 unchanged", ft_toupper('1') == '1');

	printf("\n========== TOLOWER ==========\n");

	check("A -> a", ft_tolower('A') == 'a');
	check("Z -> z", ft_tolower('Z') == 'z');
	check("a unchanged", ft_tolower('a') == 'a');
	check("1 unchanged", ft_tolower('1') == '1');
}

/* ========================================================= */
/*                   STRCHR / STRRCHR                        */
/* ========================================================= */

static void	test_strchr(void)
{
	const char	*s = "Hello World";

	printf("\n========== STRCHR ==========\n");

	check("first l", ft_strchr(s, 'l') == &s[2]);
	check("H", ft_strchr(s, 'H') == s);
	check("not found", ft_strchr(s, 'X') == NULL);
	check("null terminator", ft_strchr(s, '\0') == &s[11]);
}

static void	test_strrchr(void)
{
	const char	*s = "Hello World";

	printf("\n========== STRRCHR ==========\n");

	check("last l", ft_strrchr(s, 'l') == &s[9]);
	check("H", ft_strrchr(s, 'H') == s);
	check("not found", ft_strrchr(s, 'X') == NULL);
	check("null terminator", ft_strrchr(s, '\0') == &s[11]);
}

/* ========================================================= */
/*                         STRNCMP                           */
/* ========================================================= */

static void	test_strncmp(void)
{
	printf("\n========== STRNCMP ==========\n");

	check("equal", ft_strncmp("abc", "abc", 3) == 0);
	check("first smaller", ft_strncmp("abc", "abd", 3) < 0);
	check("first bigger", ft_strncmp("abe", "abd", 3) > 0);
	check("n zero", ft_strncmp("abc", "xyz", 0) == 0);
	check("first 2 equal", ft_strncmp("abc", "abd", 2) == 0);
	check("different length", ft_strncmp("abc", "abcd", 4) < 0);
}

/* ========================================================= */
/*                         MEMCHR                            */
/* ========================================================= */

static void	test_memchr(void)
{
	char	str[] = "abcabc";

	printf("\n========== MEMCHR ==========\n");

	check("find a", ft_memchr(str, 'a', 6) == &str[0]);
	check("find b", ft_memchr(str, 'b', 6) == &str[1]);
	check("limited search", ft_memchr(str, 'c', 2) == NULL);
	check("not found", ft_memchr(str, 'X', 6) == NULL);
	check("zero length", ft_memchr(str, 'a', 0) == NULL);
}

/* ========================================================= */
/*                         MEMCMP                            */
/* ========================================================= */

static void	test_memcmp(void)
{
	printf("\n========== MEMCMP ==========\n");

	check("equal", ft_memcmp("abc", "abc", 3) == 0);
	check("smaller", ft_memcmp("abc", "abd", 3) < 0);
	check("bigger", ft_memcmp("abd", "abc", 3) > 0);
	check("zero bytes", ft_memcmp("abc", "xyz", 0) == 0);
	check("first bytes equal", ft_memcmp("abcdef", "abcxyz", 3) == 0);
}

/* ========================================================= */
/*                         STRNSTR                           */
/* ========================================================= */

static void	test_strnstr(void)
{
	const char	*s = "Hello beautiful World";

	printf("\n========== STRNSTR ==========\n");

	check("find beautiful",
		ft_strnstr(s, "beautiful", 21) == &s[6]);

	check("find Hello",
		ft_strnstr(s, "Hello", 5) == s);

	check("not enough len",
		ft_strnstr(s, "World", 10) == NULL);

	check("empty little",
		ft_strnstr(s, "", 5) == s);

	check("not found",
		ft_strnstr(s, "Apple", 21) == NULL);

	check("repeated pattern",
		ft_strnstr("aaabc", "aab", 5) != NULL);
}

/* ========================================================= */
/*                           ATOI                            */
/* ========================================================= */

static void	test_atoi(void)
{
	printf("\n========== ATOI ==========\n");

	check("42", ft_atoi("42") == 42);
	check("-42", ft_atoi("-42") == -42);
	check("+42", ft_atoi("+42") == 42);
	check("spaces", ft_atoi("   123") == 123);
	check("all whitespace", ft_atoi("\t\n\v\f\r 42") == 42);
	check("text after", ft_atoi("123abc") == 123);
	check("text before", ft_atoi("abc123") == 0);
	check("double minus", ft_atoi("--123") == 0);
	check("plus minus", ft_atoi("+-123") == 0);
	check("zero", ft_atoi("0") == 0);
	check("negative zero", ft_atoi("-0") == 0);
}

/* ========================================================= */
/*                          CALLOC                           */
/* ========================================================= */

static void	test_calloc(void)
{
	int		*arr;
	size_t	i;
	void	*zero;
	void	*overflow;
	int		all_zero;

	printf("\n========== CALLOC ==========\n");

	arr = ft_calloc(5, sizeof(int));
	check("allocation", arr != NULL);

	all_zero = 1;
	if (arr != NULL)
	{
		i = 0;
		while (i < 5)
		{
			if (arr[i] != 0)
				all_zero = 0;
			i++;
		}
	}
	check("memory zeroed", arr != NULL && all_zero);
	free(arr);

	zero = ft_calloc(0, sizeof(int));
	check("zero count returns pointer", zero != NULL);
	free(zero);

	zero = ft_calloc(10, 0);
	check("zero size returns pointer", zero != NULL);
	free(zero);

	overflow = ft_calloc((size_t)-1, 2);
	check("overflow returns NULL", overflow == NULL);
	free(overflow);
}

/* ========================================================= */
/*                          STRDUP                           */
/* ========================================================= */

static void	test_strdup(void)
{
	char	*copy;
	char	original[] = "Hello";

	printf("\n========== STRDUP ==========\n");

	copy = ft_strdup(original);
	check("normal copy", copy != NULL && strcmp(copy, "Hello") == 0);

	if (copy != NULL)
		copy[0] = 'X';

	check("independent memory", strcmp(original, "Hello") == 0);
	free(copy);

	copy = ft_strdup("");
	check("empty string", copy != NULL && strcmp(copy, "") == 0);
	free(copy);
}

/* ========================================================= */
/*                          SUBSTR                           */
/* ========================================================= */

static void	test_substr(void)
{
	char	*str;

	printf("\n========== SUBSTR ==========\n");

	str = ft_substr("Hello World", 6, 5);
	check("World", str != NULL && strcmp(str, "World") == 0);
	free(str);

	str = ft_substr("abcdef", 2, 3);
	check("cde", str != NULL && strcmp(str, "cde") == 0);
	free(str);

	str = ft_substr("abc", 10, 5);
	check("start outside", str != NULL && strcmp(str, "") == 0);
	free(str);

	str = ft_substr("abc", 1, 100);
	check("len too big", str != NULL && strcmp(str, "bc") == 0);
	free(str);

	str = ft_substr("abc", 1, 0);
	check("len zero", str != NULL && strcmp(str, "") == 0);
	free(str);

	str = ft_substr("", 0, 10);
	check("empty source", str != NULL && strcmp(str, "") == 0);
	free(str);
}

/* ========================================================= */
/*                         STRJOIN                           */
/* ========================================================= */

static void	test_strjoin(void)
{
	char	*str;

	printf("\n========== STRJOIN ==========\n");

	str = ft_strjoin("Hello ", "World");
	check("normal", str != NULL && strcmp(str, "Hello World") == 0);
	free(str);

	str = ft_strjoin("", "World");
	check("empty first", str != NULL && strcmp(str, "World") == 0);
	free(str);

	str = ft_strjoin("Hello", "");
	check("empty second", str != NULL && strcmp(str, "Hello") == 0);
	free(str);

	str = ft_strjoin("", "");
	check("both empty", str != NULL && strcmp(str, "") == 0);
	free(str);

	str = ft_strjoin("42", "Prague");
	check("42Prague", str != NULL && strcmp(str, "42Prague") == 0);
	free(str);
}

/* ========================================================= */
/*                         STRTRIM                           */
/* ========================================================= */

static void	test_strtrim(void)
{
	char	*str;

	printf("\n========== STRTRIM ==========\n");

	str = ft_strtrim("aaHelloaa", "a");
	check("single set char", str != NULL && strcmp(str, "Hello") == 0);
	free(str);

	str = ft_strtrim("abcHelloabc", "abc");
	check("multiple set chars", str != NULL && strcmp(str, "Hello") == 0);
	free(str);

	str = ft_strtrim("   Hello   ", " ");
	check("spaces", str != NULL && strcmp(str, "Hello") == 0);
	free(str);

	str = ft_strtrim("Hello", "xyz");
	check("nothing removed", str != NULL && strcmp(str, "Hello") == 0);
	free(str);

	str = ft_strtrim("aaaa", "a");
	check("everything removed", str != NULL && strcmp(str, "") == 0);
	free(str);

	str = ft_strtrim("", "abc");
	check("empty source", str != NULL && strcmp(str, "") == 0);
	free(str);

	str = ft_strtrim("Hello", "");
	check("empty set", str != NULL && strcmp(str, "Hello") == 0);
	free(str);
}

/* ========================================================= */
/*                          SPLIT                            */
/* ========================================================= */

static int	split_equals(char **result, const char **expected)
{
	size_t	i;

	if (result == NULL)
		return (0);
	i = 0;
	while (result[i] != NULL && expected[i] != NULL)
	{
		if (strcmp(result[i], expected[i]) != 0)
			return (0);
		i++;
	}
	return (result[i] == NULL && expected[i] == NULL);
}

static void	free_test_split(char **result)
{
	size_t	i;

	if (result == NULL)
		return ;
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static void	test_split(void)
{
	char			**result;
	const char		*e1[] = {"Hello", "World", NULL};
	const char		*e2[] = {"Hello", "World", NULL};
	const char		*e3[] = {"abc", NULL};
	const char		*e4[] = {NULL};
	const char		*e5[] = {"abc", "def", NULL};
	const char		*e6[] = {"a", "b", "c", "d", NULL};
	const char		*e7[] = {"one", "two", "three", NULL};

	printf("\n========== SPLIT ==========\n");

	result = ft_split("Hello World", ' ');
	check("normal", split_equals(result, e1));
	free_test_split(result);

	result = ft_split("   Hello    World   ", ' ');
	check("multiple delimiters", split_equals(result, e2));
	free_test_split(result);

	result = ft_split("abc", ' ');
	check("no delimiter", split_equals(result, e3));
	free_test_split(result);

	result = ft_split("", ' ');
	check("empty string", split_equals(result, e4));
	free_test_split(result);

	result = ft_split("------", '-');
	check("only delimiters", split_equals(result, e4));
	free_test_split(result);

	result = ft_split("---abc---def---", '-');
	check("delimiter around words", split_equals(result, e5));
	free_test_split(result);

	result = ft_split("a-b-c-d", '-');
	check("many words", split_equals(result, e6));
	free_test_split(result);

	result = ft_split("one,two,three", ',');
	check("comma delimiter", split_equals(result, e7));
	free_test_split(result);
}

/* ========================================================= */
/*                           ITOA                            */
/* ========================================================= */

static void	check_itoa(const char *name, int n, const char *expected)
{
	char	*result;

	result = ft_itoa(n);
	check(name, result != NULL && strcmp(result, expected) == 0);
	free(result);
}

static void	test_itoa(void)
{
	printf("\n========== ITOA ==========\n");

	check_itoa("zero", 0, "0");
	check_itoa("one", 1, "1");
	check_itoa("42", 42, "42");
	check_itoa("-1", -1, "-1");
	check_itoa("-42", -42, "-42");
	check_itoa("10", 10, "10");
	check_itoa("1000", 1000, "1000");
	check_itoa("-1000", -1000, "-1000");
	check_itoa("INT_MAX", INT_MAX, "2147483647");
	check_itoa("INT_MIN", INT_MIN, "-2147483648");
}

/* ========================================================= */
/*                         STRMAPI                           */
/* ========================================================= */

static char	map_identity(unsigned int i, char c)
{
	(void)i;
	return (c);
}

static char	map_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ((char)ft_toupper(c));
	return (c);
}

static char	map_with_index(unsigned int i, char c)
{
	return ((char)(c + i));
}

static void	test_strmapi(void)
{
	char	*result;

	printf("\n========== STRMAPI ==========\n");

	result = ft_strmapi("Hello", map_identity);
	check("identity", result != NULL && strcmp(result, "Hello") == 0);
	free(result);

	result = ft_strmapi("hello", map_upper_even);
	check("upper even", result != NULL && strcmp(result, "HeLlO") == 0);
	free(result);

	result = ft_strmapi("aaaa", map_with_index);
	check("index modification", result != NULL
		&& strcmp(result, "abcd") == 0);
	free(result);

	result = ft_strmapi("", map_identity);
	check("empty", result != NULL && strcmp(result, "") == 0);
	free(result);

	result = ft_strmapi("abcdef", map_upper_even);
	check("abcdef", result != NULL && strcmp(result, "AbCdEf") == 0);
	free(result);
}

/* ========================================================= */
/*                        STRITERI                           */
/* ========================================================= */

static void	iter_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = (char)ft_toupper(*c);
}

static void	iter_with_index(unsigned int i, char *c)
{
	*c = (char)(*c + i);
}

static void	test_striteri(void)
{
	char	str1[] = "hello";
	char	str2[] = "aaaa";
	char	str3[] = "";
	char	str4[] = "abcdef";

	printf("\n========== STRITERI ==========\n");

	ft_striteri(str1, iter_upper_even);
	check("upper even", strcmp(str1, "HeLlO") == 0);

	ft_striteri(str2, iter_with_index);
	check("index modification", strcmp(str2, "abcd") == 0);

	ft_striteri(str3, iter_upper_even);
	check("empty", strcmp(str3, "") == 0);

	ft_striteri(str4, iter_upper_even);
	check("abcdef", strcmp(str4, "AbCdEf") == 0);
}

/* ========================================================= */
/*                       PUTCHAR_FD                          */
/* ========================================================= */

static void	test_putchar_fd(void)
{
	int		fd[2];
	char	buffer[10];
	ssize_t	n;

	printf("\n========== PUTCHAR_FD ==========\n");

	if (pipe(fd) == -1)
	{
		check("pipe", 0);
		return ;
	}

	ft_putchar_fd('A', fd[1]);
	ft_putchar_fd('4', fd[1]);
	ft_putchar_fd('\n', fd[1]);

	close(fd[1]);

	n = read(fd[0], buffer, sizeof(buffer));
	close(fd[0]);

	check("bytes written", n == 3);

	if (n == 3)
	{
		check("A", buffer[0] == 'A');
		check("4", buffer[1] == '4');
		check("newline", buffer[2] == '\n');
	}
}

/* ========================================================= */
/*                        PUTSTR_FD                          */
/* ========================================================= */

static void	check_putstr(const char *name, char *str,
		const char *expected)
{
	int		fd[2];
	char	buffer[100];
	ssize_t	n;

	if (pipe(fd) == -1)
	{
		check(name, 0);
		return ;
	}

	ft_putstr_fd(str, fd[1]);
	close(fd[1]);

	n = read(fd[0], buffer, sizeof(buffer) - 1);
	close(fd[0]);

	if (n < 0)
	{
		check(name, 0);
		return ;
	}

	buffer[n] = '\0';
	check(name, strcmp(buffer, expected) == 0);
}

static void	test_putstr_fd(void)
{
	printf("\n========== PUTSTR_FD ==========\n");

	check_putstr("Hello", "Hello", "Hello");
	check_putstr("Hello World", "Hello World", "Hello World");
	check_putstr("empty", "", "");
	check_putstr("numbers", "12345", "12345");
	check_putstr("newline", "Hello\nWorld", "Hello\nWorld");
	check_putstr("symbols", "!@#$%", "!@#$%");
}
static void	check_putendl(const char *name, char *str,
		const char *expected)
{
	int		fd[2];
	char	buffer[100];
	ssize_t	n;

	if (pipe(fd) == -1)
	{
		check(name, 0);
		return ;
	}
	ft_putendl_fd(str, fd[1]);
	close(fd[1]);
	n = read(fd[0], buffer, sizeof(buffer) - 1);
	close(fd[0]);
	if (n < 0)
	{
		check(name, 0);
		return ;
	}
	buffer[n] = '\0';
	check(name, strcmp(buffer, expected) == 0);
}

static void	test_putendl_fd(void)
{
	printf("\n========== PUTENDL_FD ==========\n");

	check_putendl("Hello", "Hello", "Hello\n");
	check_putendl("empty", "", "\n");
	check_putendl("numbers", "12345", "12345\n");
	check_putendl("spaces", "Hello World", "Hello World\n");
	check_putendl("symbols", "!@#$%", "!@#$%\n");
	check_putendl("already newline", "Hello\n", "Hello\n\n");
}
/* ========================================================= */
/*                           MAIN                            */
/* ========================================================= */
static void	check_putnbr(const char *name, int number,
		const char *expected)
{
	int		fd[2];
	char	buffer[100];
	ssize_t	n;

	if (pipe(fd) == -1)
	{
		check(name, 0);
		return ;
	}
	ft_putnbr_fd(number, fd[1]);
	close(fd[1]);
	n = read(fd[0], buffer, sizeof(buffer) - 1);
	close(fd[0]);
	if (n < 0)
	{
		check(name, 0);
		return ;
	}
	buffer[n] = '\0';
	check(name, strcmp(buffer, expected) == 0);
}

static void	test_putnbr_fd(void)
{
	printf("\n========== PUTNBR_FD ==========\n");

	check_putnbr("zero", 0, "0");
	check_putnbr("one digit", 7, "7");
	check_putnbr("positive", 42, "42");
	check_putnbr("large positive", 123456, "123456");

	check_putnbr("negative", -42, "-42");
	check_putnbr("negative one", -1, "-1");
	check_putnbr("large negative", -123456, "-123456");

	check_putnbr("10", 10, "10");
	check_putnbr("1000", 1000, "1000");

	check_putnbr("INT_MAX", 2147483647, "2147483647");
	check_putnbr("INT_MIN", -2147483647 - 1, "-2147483648");
}
static void	test_lstnew(void)
{
	t_list	*node;
	char	*str;
	int		number;

	printf("\n========== LSTNEW ==========\n");

	str = "Hello";
	node = ft_lstnew(str);
	check("node created", node != NULL);
	if (node != NULL)
	{
		check("string content", node->content == str);
		check("next is NULL", node->next == NULL);
		free(node);
	}

	number = 42;
	node = ft_lstnew(&number);
	check("int node created", node != NULL);
	if (node != NULL)
	{
		check("int content", *(int *)node->content == 42);
		check("int next is NULL", node->next == NULL);
		free(node);
	}

	node = ft_lstnew(NULL);
	check("NULL content node created", node != NULL);
	if (node != NULL)
	{
		check("content is NULL", node->content == NULL);
		check("NULL content next is NULL", node->next == NULL);
		free(node);
	}
}
static void	test_lstadd_front(void)
{
	t_list	*lst;
	t_list	*first;
	t_list	*second;
	t_list	*third;

	printf("\n========== LSTADD_FRONT ==========\n");

	lst = NULL;
	first = ft_lstnew("A");

	ft_lstadd_front(&lst, first);

	check("add to empty list", lst == first);
	check("first content", strcmp((char *)lst->content, "A") == 0);
	check("first next NULL", lst->next == NULL);

	second = ft_lstnew("B");

	ft_lstadd_front(&lst, second);

	check("new first is B", lst == second);
	check("B content", strcmp((char *)lst->content, "B") == 0);
	check("B next points to A", lst->next == first);
	check("A still next NULL", first->next == NULL);

	third = ft_lstnew("C");

	ft_lstadd_front(&lst, third);

	check("new first is C", lst == third);
	check("C next points to B", third->next == second);
	check("B next points to A", second->next == first);
	check("A next NULL", first->next == NULL);

	free(third);
	free(second);
	free(first);
}
static void	test_lstsize(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;

	printf("\n========== LSTSIZE ==========\n");

	lst = NULL;
	check("empty list", ft_lstsize(lst) == 0);

	a = ft_lstnew("A");
	check("one element", ft_lstsize(a) == 1);

	b = ft_lstnew("B");
	a->next = b;
	check("two elements", ft_lstsize(a) == 2);

	c = ft_lstnew("C");
	b->next = c;
	check("three elements", ft_lstsize(a) == 3);

	d = ft_lstnew("D");
	c->next = d;
	check("four elements", ft_lstsize(a) == 4);

	free(d);
	free(c);
	free(b);
	free(a);
}static void	test_lstlast(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*last;

	printf("\n========== LSTLAST ==========\n");

	lst = NULL;
	last = ft_lstlast(lst);
	check("empty list", last == NULL);

	a = ft_lstnew("A");
	last = ft_lstlast(a);
	check("one element", last == a);
	check("one element content",
		strcmp((char *)last->content, "A") == 0);

	b = ft_lstnew("B");
	a->next = b;

	last = ft_lstlast(a);
	check("two elements", last == b);
	check("last content B",
		strcmp((char *)last->content, "B") == 0);
	check("last next NULL", last->next == NULL);

	c = ft_lstnew("C");
	b->next = c;

	last = ft_lstlast(a);
	check("three elements", last == c);
	check("last content C",
		strcmp((char *)last->content, "C") == 0);
	check("C next NULL", last->next == NULL);

	free(c);
	free(b);
	free(a);
}
static void	test_lstadd_back(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	printf("\n========== LSTADD_BACK ==========\n");

	lst = NULL;
	a = ft_lstnew("A");

	ft_lstadd_back(&lst, a);

	check("add A to empty list", lst == a);
	check("A content", strcmp((char *)lst->content, "A") == 0);
	check("A next NULL", a->next == NULL);
	check("size after A", ft_lstsize(lst) == 1);

	b = ft_lstnew("B");
	ft_lstadd_back(&lst, b);

	check("first still A", lst == a);
	check("A next is B", a->next == b);
	check("B next NULL", b->next == NULL);
	check("last is B", ft_lstlast(lst) == b);
	check("size after B", ft_lstsize(lst) == 2);

	c = ft_lstnew("C");
	ft_lstadd_back(&lst, c);

	check("first still A after C", lst == a);
	check("A next B", a->next == b);
	check("B next C", b->next == c);
	check("C next NULL", c->next == NULL);
	check("last is C", ft_lstlast(lst) == c);
	check("size after C", ft_lstsize(lst) == 3);

	free(c);
	free(b);
	free(a);
}
static int	g_del_called;

static void	test_del(void *content)
{
	g_del_called++;
	free(content);
}

static void	test_lstdelone(void)
{
	t_list	*node;
	char	*content;

	printf("\n========== LSTDELONE ==========\n");

	g_del_called = 0;

	content = ft_strdup("Hello");
	node = ft_lstnew(content);

	check("node created", node != NULL);
	check("content created", content != NULL);

	if (node != NULL)
	{
		ft_lstdelone(node, test_del);
		check("del function called", g_del_called == 1);
	}

	g_del_called = 0;
	ft_lstdelone(NULL, test_del);
	check("NULL node does nothing", g_del_called == 0);
}
static int	g_clear_del_called;

static void	clear_del(void *content)
{
	g_clear_del_called++;
	free(content);
}

static void	test_lstclear(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	printf("\n========== LSTCLEAR ==========\n");

	g_clear_del_called = 0;

	a = ft_lstnew(ft_strdup("A"));
	b = ft_lstnew(ft_strdup("B"));
	c = ft_lstnew(ft_strdup("C"));

	a->next = b;
	b->next = c;
	c->next = NULL;

	lst = a;

	check("size before clear", ft_lstsize(lst) == 3);

	ft_lstclear(&lst, clear_del);

	check("list becomes NULL", lst == NULL);
	check("del called 3 times", g_clear_del_called == 3);

	g_clear_del_called = 0;
	lst = NULL;

	ft_lstclear(&lst, clear_del);

	check("clear empty list", lst == NULL);
	check("del not called for empty", g_clear_del_called == 0);
}
static int	g_iter_called;

static void	iter_to_upper(void *content)
{
	char	*str;

	str = (char *)content;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	g_iter_called++;
}

static void	test_lstiter(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	printf("\n========== LSTITER ==========\n");

	a = ft_lstnew(ft_strdup("apple"));
	b = ft_lstnew(ft_strdup("banana"));
	c = ft_lstnew(ft_strdup("cat"));

	a->next = b;
	b->next = c;

	g_iter_called = 0;

	ft_lstiter(a, iter_to_upper);

	check("function called 3 times", g_iter_called == 3);
	check("first content changed",
		strcmp((char *)a->content, "Apple") == 0);
	check("second content changed",
		strcmp((char *)b->content, "Banana") == 0);
	check("third content changed",
		strcmp((char *)c->content, "Cat") == 0);

	g_iter_called = 0;
	ft_lstiter(NULL, iter_to_upper);
	check("empty list calls nothing", g_iter_called == 0);

	ft_lstclear(&a, free);
}
static void	*map_duplicate_upper(void *content)
{
	char	*src;
	char	*copy;
	size_t	i;

	src = (char *)content;
	copy = ft_strdup(src);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (copy[i] != '\0')
	{
		copy[i] = (char)ft_toupper(copy[i]);
		i++;
	}
	return (copy);
}

static void	test_lstmap(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*new_list;

	printf("\n========== LSTMAP ==========\n");

	a = ft_lstnew(ft_strdup("apple"));
	b = ft_lstnew(ft_strdup("banana"));
	c = ft_lstnew(ft_strdup("cat"));

	a->next = b;
	b->next = c;

	new_list = ft_lstmap(a, map_duplicate_upper, free);

	check("new list created", new_list != NULL);

	if (new_list != NULL)
	{
		check("new size", ft_lstsize(new_list) == 3);

		check("first mapped",
			strcmp((char *)new_list->content, "APPLE") == 0);

		check("second mapped",
			strcmp((char *)new_list->next->content, "BANANA") == 0);

		check("third mapped",
			strcmp((char *)new_list->next->next->content, "CAT") == 0);

		check("original first unchanged",
			strcmp((char *)a->content, "apple") == 0);

		check("original second unchanged",
			strcmp((char *)b->content, "banana") == 0);

		check("different first node",
			new_list != a);

		check("different first content",
			new_list->content != a->content);
	}

	ft_lstclear(&new_list, free);
	ft_lstclear(&a, free);
}
int	main(void)
{
	printf("\n");
	printf("=============================================\n");
	printf("             LIBFT TESTER\n");
	printf("=============================================\n");

	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();

	test_strlen();

	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();

	test_strlcpy();
	test_strlcat();

	test_case_conversion();

	test_strchr();
	test_strrchr();
	test_strncmp();

	test_memchr();
	test_memcmp();
	test_strnstr();

	test_atoi();
	test_calloc();
	test_strdup();

	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();

	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstadd_back();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();
	printf("\n");
	printf("=============================================\n");
	printf("Passed: %d\n", g_passed);
	printf("Failed: %d\n", g_failed);
	printf("Total:  %d\n", g_passed + g_failed);
	printf("=============================================\n");

	if (g_failed == 0)
		printf("ALL TESTS PASSED\n");
	else
		printf("SOME TESTS FAILED\n");

	printf("=============================================\n");

	return (g_failed != 0);
}