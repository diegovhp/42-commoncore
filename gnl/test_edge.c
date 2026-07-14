#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int	g_pass = 0;
static int	g_fail = 0;

static void	check(const char *desc, int cond)
{
	if (cond)
	{
		printf("  PASS: %s\n", desc);
		g_pass++;
	}
	else
	{
		printf("  FAIL: %s\n", desc);
		g_fail++;
	}
}

static void	test_double_newline(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*l3;
	char	*l4;

	printf("\n[double newline: \"hello\\n\\nworld\\n\"]\n");
	fd = open("test_double_nl.txt", O_RDONLY);
	assert(fd >= 0);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	l3 = get_next_line(fd);
	l4 = get_next_line(fd);
	check("line1 = 'hello\\n'", l1 && strcmp(l1, "hello\n") == 0);
	check("line2 = '\\n'", l2 && strcmp(l2, "\n") == 0);
	check("line3 = 'world\\n'", l3 && strcmp(l3, "world\n") == 0);
	check("line4 = NULL (EOF)", l4 == NULL);
	free(l1);
	free(l2);
	free(l3);
	close(fd);
}

static void	test_single_char_no_nl(void)
{
	int		fd;
	char	*l1;
	char	*l2;

	printf("\n[single char no newline: \"a\"]\n");
	fd = open("test_1char.txt", O_RDONLY);
	assert(fd >= 0);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	check("line1 = 'a'", l1 && strcmp(l1, "a") == 0);
	check("line2 = NULL", l2 == NULL);
	free(l1);
	close(fd);
}

static void	test_triple_newlines(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*l3;
	char	*l4;

	printf("\n[triple newlines: \"\\n\\n\\n\"]\n");
	fd = open("test_triple_nl.txt", O_RDONLY);
	assert(fd >= 0);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	l3 = get_next_line(fd);
	l4 = get_next_line(fd);
	check("line1 = '\\n'", l1 && strcmp(l1, "\n") == 0);
	check("line2 = '\\n'", l2 && strcmp(l2, "\n") == 0);
	check("line3 = '\\n'", l3 && strcmp(l3, "\n") == 0);
	check("line4 = NULL", l4 == NULL);
	free(l1);
	free(l2);
	free(l3);
	close(fd);
}

static void	test_long_line(void)
{
	int		fd;
	char	*l1;
	char	*l2;

	printf("\n[long line: 5001 chars (5000 + newline)]\n");
	fd = open("test_long_line.txt", O_RDONLY);
	assert(fd >= 0);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	check("line1 != NULL", l1 != NULL);
	check("line1 ends with '\\n'", l1 && l1[strlen(l1) - 1] == '\n');
	check("line1 length = 5001", l1 && strlen(l1) == 5001);
	check("line2 = NULL", l2 == NULL);
	free(l1);
	close(fd);
}

static void	test_100_lines(void)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n[100 lines file]\n");
	fd = open("test_100lines.txt", O_RDONLY);
	assert(fd >= 0);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count++;
	}
	check("exactly 100 lines", count == 100);
	close(fd);
}

static void	test_mixed_end(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*l3;
	char	*l4;

	printf("\n[mixed end: \"line1\\nline2\\nno_newline_at_end\"]\n");
	fd = open("test_mixed_end.txt", O_RDONLY);
	assert(fd >= 0);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	l3 = get_next_line(fd);
	l4 = get_next_line(fd);
	check("line1 = 'line1\\n'", l1 && strcmp(l1, "line1\n") == 0);
	check("line2 = 'line2\\n'", l2 && strcmp(l2, "line2\n") == 0);
	check("line3 = 'no_newline_at_end'", l3 && strcmp(l3, "no_newline_at_end") == 0);
	check("line4 = NULL", l4 == NULL);
	free(l1);
	free(l2);
	free(l3);
	close(fd);
}

static void	test_multiple_eof_calls(void)
{
	int		fd;
	char	*line;
	int		i;

	printf("\n[multiple calls after EOF]\n");
	fd = open("test_1char.txt", O_RDONLY);
	assert(fd >= 0);
	line = get_next_line(fd);
	check("first call = 'a'", line && strcmp(line, "a") == 0);
	free(line);
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd);
		check("post-EOF call returns NULL", line == NULL);
		i++;
	}
	close(fd);
}

static void	test_invalid_fds(void)
{
	printf("\n[invalid file descriptors]\n");
	check("fd=-1 returns NULL", get_next_line(-1) == NULL);
	check("fd=-100 returns NULL", get_next_line(-100) == NULL);
	check("fd=99999 returns NULL (no open file)", get_next_line(99999) == NULL);
}

int	main(void)
{
	printf("=== EDGE CASE TESTS (BUFFER_SIZE=%d) ===\n", BUFFER_SIZE);
	test_single_char_no_nl();
	test_double_newline();
	test_triple_newlines();
	test_long_line();
	test_100_lines();
	test_mixed_end();
	test_multiple_eof_calls();
	test_invalid_fds();
	printf("\nResults: %d passed, %d failed\n", g_pass, g_fail);
	return (g_fail != 0);
}
