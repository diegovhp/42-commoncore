#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static void	print_result(const char *label, char *line)
{
	if (line)
		printf("[%s] => \"%s\"\n", label, line);
	else
		printf("[%s] => NULL\n", label);
}

static void	test_multiline(void)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n=== test_multiline ===\n");
	fd = open("test_multi.txt", O_RDONLY);
	assert(fd >= 0);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		print_result("line", line);
		free(line);
		count++;
	}
	printf("total lines: %d\n", count);
	assert(count == 4);
	close(fd);
}

static void	test_no_newline(void)
{
	int		fd;
	char	*line;

	printf("\n=== test_no_newline ===\n");
	fd = open("test_nonl.txt", O_RDONLY);
	assert(fd >= 0);
	line = get_next_line(fd);
	print_result("line1", line);
	assert(line != NULL);
	assert(strcmp(line, "hello world") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("line2 (should be NULL)", line);
	assert(line == NULL);
	close(fd);
}

static void	test_empty_file(void)
{
	int		fd;
	char	*line;

	printf("\n=== test_empty_file ===\n");
	fd = open("test_empty.txt", O_RDONLY);
	assert(fd >= 0);
	line = get_next_line(fd);
	print_result("empty file (should be NULL)", line);
	assert(line == NULL);
	close(fd);
}

static void	test_single_newline(void)
{
	int		fd;
	char	*line;

	printf("\n=== test_single_newline ===\n");
	fd = open("test_single_nl.txt", O_RDONLY);
	assert(fd >= 0);
	line = get_next_line(fd);
	print_result("single newline", line);
	assert(line != NULL);
	assert(strcmp(line, "\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("after newline (should be NULL)", line);
	assert(line == NULL);
	close(fd);
}

static void	test_stdin_invalid(void)
{
	char	*line;

	printf("\n=== test_invalid_fd ===\n");
	line = get_next_line(-1);
	print_result("fd=-1 (should be NULL)", line);
	assert(line == NULL);
}

int	main(void)
{
	printf("=== GNL Tests (BUFFER_SIZE=%d) ===\n", BUFFER_SIZE);
	test_empty_file();
	test_no_newline();
	test_single_newline();
	test_multiline();
	test_stdin_invalid();
	printf("\nAll tests passed!\n");
	return (0);
}
