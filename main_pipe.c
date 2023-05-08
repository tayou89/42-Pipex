#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define BUF_MAX 1024

int	main(void)
{
	int		fd[2];
	pid_t	pid;
	char	buf[BUF_MAX];

	if (pipe(fd) < 0)
		printf("Pipe Error\n");
	pid = fork();
	if (pid < 0)
		printf("Fork Error\n");
	if (pid == 0)
	{
		close(fd[1]);
		read(fd[0], buf, BUF_MAX);
		printf("Child got message: %s\n", buf);
	}
	else
	{
		close(fd[0]);
		strcpy(buf, "Message from Parent.");
		write(fd[1], buf, strlen(buf));
	}
	return (0);
}
