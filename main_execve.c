#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	char	*command_path;
	char	*command[3];

	command_path = "/bin/ls";
	if (argc < 1)
		return (0);
	if (argv[0] == (void *) 0)
		return (0);
	command[0] = "ls";
	command[1] = "-al";
	command[2] = (void *) 0;
	execve(command_path, command, envp);
	return (0);
}
