#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	int	stat;
	int	stat_result;

	if (fork() == 0)
		printf("Hi Child!\n");
	else
	{
		stat_result = wait(&stat);
		printf("Hi Parent\n");
		printf("wait argument: %d\nwait return: %d\n", stat, stat_result);
		wait((void *) 0);
		printf("Bye Child\n");
	}
	printf("Bye Process\n");
	return (0);
}
