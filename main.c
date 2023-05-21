#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"

#define BUF_SIZE	10

int	get_output_line_count(void);
int	count_line_in_string(char *string, int read_size);

int	main(void)
{
	int	fd;
	int	line_count;
	int	dup2_return;

	fd = open("./test.txt", O_RDWR | O_APPEND);
	if (fd == -1)
		return (1);
	dup2_return = dup2(fd, 1);
	if (dup2_return == -1)
		return (1);
	printf("dup2_return: %d\n", dup2_return);
	line_count = get_output_line_count();
	printf("line_count: %d\n", line_count);
	return (0);
}

int	get_output_line_count(void)
{
	char	buf[BUF_SIZE];
	int		read_size;
	int		count;
	int		line_count;

	line_count = 0;
	read_size = read(1, buf, BUF_SIZE - 1);
	if (read_size == -1)
		exit(1);
	while (read_size != 0)
	{
		count = 0;
		count = count_line_in_string(buf, read_size);
		line_count += count;
		read_size = read(1, buf, BUF_SIZE -1);
		if (read_size == -1)
			exit(1);
		if (read_size == 0 && count == 0)
			line_count++;
	}
	return (line_count);
}

int	count_line_in_string(char *string, int read_size)
{
	int	count;
	int	i;

	if (string == (void *) 0)
		return (0);
	count = 0;
	i = 0;
	while (i < read_size)
	{
		if (string[i] == '\n')
			count++;
		i++;
	}
	return (count);
}
