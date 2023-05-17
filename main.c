#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		return (0);
	if (argv == (void *) 0)
		return (0);
	if (envp == (void *) 0)
		return (0);
	printf("O_TRUNC: %d\n", O_TRUNC);
	return (0);
}
