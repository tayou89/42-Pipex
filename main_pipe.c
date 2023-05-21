#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUF_MAX 1024

void	do_parent_process(pid_t pid, int fd[2]);
void	do_child_process(pid_t pid, int fd[2]);

int	main(void)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid != 0)
		do_parent_process(pid, fd);
	else if (pid == 0)
		do_child_process(pid, fd);
	return (0);
}

void	do_parent_process(pid_t pid, int fd[2])
{
	char	*write_string;
	int		stat_loc;
	int		wait_return;

	write_string = "Hello, child!";
	printf("This is parent process\n");
	printf("Parent pid: %d\n", pid);
	close(fd[0]);
	write(fd[1], write_string, strlen(write_string));
	wait_return = waitpid(pid, &stat_loc, 0);
	printf("wait_return: %d\n", wait_return);
	printf("stat_loc: %d\n", stat_loc);
}

void	do_child_process(pid_t pid, int fd[2])
{
	char	buf[1000];
	int		read_size;

	printf("This is child process\n");
	printf("Child pid: %d\n", pid);
	close(fd[1]);
	read_size = read(fd[0], buf, 1000);
	buf[read_size] = '\0';
	printf("Message from parent: %s\n", buf);
	printf("read_size: %d\n", read_size);
}


