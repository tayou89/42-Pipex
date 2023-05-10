#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	int	status;
	int	status_result;
	int	pid_1;
	int	pid_2;

	pid_1 = fork();
	if (pid_1 == -1)
		return (1);
	else if (pid_1 == 0)
	{
		printf("This is first child process\n");
		printf("child pid_1: %d\n", pid_1);
		return (2);
	}
	else
	{
		pid_2 = fork();
		if (pid_2 == -1)
			return (1);
		else if (pid_2 == 0)
		{
			printf("This is second child process\n");
			printf("child pid_2: %d\n", pid_2);
			return (3);
		}
		else
		{
			printf("This is parent process\n");
			status_result = waitpid(pid_1, &status, 0);
			printf("Successfully got status from %d child process\n", status_result);
			printf("Exit_code: %d, Signal: %d\n", WEXITSTATUS(status), WTERMSIG(status));
			printf("Current pid: %d\n", pid_1);
			status_result = waitpid(pid_2, &status, 0);
			printf("Successfully got status from %d child process\n", status_result);
			printf("Exit_code: %d, Signal: %d\n", WEXITSTATUS(status), WTERMSIG(status));
			printf("Current pid: %d\n", pid_2);
		}
	}
	printf("End process\n");
	return (0);
}
