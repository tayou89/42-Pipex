#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		fd_2;
	char	buf[10];

	fd = open("infile", O_RDONLY);
	if (fd == -1)
		return (1);
	dup2(fd, 0);
	read(0, buf, 10);
	fd_2 = open("outfile", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(fd_2, 1);
	printf("aaaaa\n");
	return (0);
}
