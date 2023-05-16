#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[3];

	if (argc != 1)
		return (0);
	if (argv == (void *) 0)
		return (0);
	if (envp == (void *) 0)
		return (0);
	if (pipe(fd) == -1)
		return (0);
	printf("fd[0]: %d\n", fd[0]);
	printf("fd[1]: %d\n", fd[1]);
	printf("fd[2]: %d\n", fd[2]);
	return (0);
}
