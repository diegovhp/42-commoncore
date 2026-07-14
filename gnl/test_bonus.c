#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static void	test_multi_fd(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*l1;
	char	*l2;
	char	*l3;

	printf("\n=== test_multi_fd (interleaved reads) ===\n");
	fd1 = open("test_multi.txt", O_RDONLY);
	fd2 = open("test_nonl.txt", O_RDONLY);
	fd3 = open("test_single_nl.txt", O_RDONLY);
	assert(fd1 >= 0 && fd2 >= 0 && fd3 >= 0);
	printf("fd1=%d fd2=%d fd3=%d\n", fd1, fd2, fd3);
	l1 = get_next_line(fd1);
	l2 = get_next_line(fd2);
	l3 = get_next_line(fd3);
	printf("fd1: \"%s\"\n", l1 ? l1 : "NULL");
	printf("fd2: \"%s\"\n", l2 ? l2 : "NULL");
	printf("fd3: \"%s\"\n", l3 ? l3 : "NULL");
	assert(l1 && strcmp(l1, "line one\n") == 0);
	assert(l2 && strcmp(l2, "hello world") == 0);
	assert(l3 && strcmp(l3, "\n") == 0);
	free(l1);
	free(l2);
	free(l3);
	l1 = get_next_line(fd1);
	printf("fd1 line2: \"%s\"\n", l1 ? l1 : "NULL");
	assert(l1 && strcmp(l1, "line two\n") == 0);
	free(l1);
	l2 = get_next_line(fd2);
	printf("fd2 line2 (NULL): \"%s\"\n", l2 ? l2 : "NULL");
	assert(l2 == NULL);
	l3 = get_next_line(fd3);
	printf("fd3 line2 (NULL): \"%s\"\n", l3 ? l3 : "NULL");
	assert(l3 == NULL);
	l1 = get_next_line(fd1);
	printf("fd1 line3: \"%s\"\n", l1 ? l1 : "NULL");
	assert(l1 && strcmp(l1, "line three\n") == 0);
	free(l1);
	l1 = get_next_line(fd1);
	printf("fd1 line4: \"%s\"\n", l1 ? l1 : "NULL");
	assert(l1 && strcmp(l1, "last line\n") == 0);
	free(l1);
	l1 = get_next_line(fd1);
	printf("fd1 line5 (NULL): \"%s\"\n", l1 ? l1 : "NULL");
	assert(l1 == NULL);
	printf("Interleaved multi-fd test passed!\n");
	close(fd1);
	close(fd2);
	close(fd3);
}

static void	test_single_fd_sequential(void)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n=== test_single_fd_sequential ===\n");
	fd = open("test_multi2.txt", O_RDONLY);
	assert(fd >= 0);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line%d: \"%s\"\n", count + 1, line);
		free(line);
		count++;
	}
	assert(count == 3);
	printf("Sequential single-fd test passed! (%d lines)\n", count);
	close(fd);
}

static void	test_invalid_fd(void)
{
	char	*line;

	printf("\n=== test_invalid_fd ===\n");
	line = get_next_line(-1);
	assert(line == NULL);
	line = get_next_line(MAX_FD);
	assert(line == NULL);
	printf("Invalid fd tests passed!\n");
}

int	main(void)
{
	printf("=== GNL BONUS Tests (BUFFER_SIZE=%d) ===\n", BUFFER_SIZE);
	test_multi_fd();
	test_single_fd_sequential();
	test_invalid_fd();
	printf("\nAll bonus tests passed!\n");
	return (0);
}
