/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:31:07 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 22:37:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define RDONLY			0
# define RDWR			2
# define CREAT			512
# define TRUNC			1024

# define STDIN			0
# define STDOUT			1

# define FILE_OK		0
# define EXEC_OK		1

# define READ			0
# define WRITE			1

# define INFILE			0
# define OUTFILE		1

# define TRUE			1
# define FALSE			0

# define MALLOC_ERROR	10
# define EXECVE_ERROR	11
# define CMD_ERROR		12
# define FORK_ERROR		13
# define OPEN_ERROR		14
# define WAIT_ERROR		15
# define CLOSE_ERROR	16
# define READ_ERROR		17
# define DUP_ERROR		18
# define PIPE_ERROR		19

typedef struct s_cmd
{
	char	**array;
	char	**split_array;
	char	**directory;
	char	*path;
	int		count;
	int		start_index;
	int		last_index;
}	t_cmd;

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_args;

typedef struct s_path
{
	char	*infile;
	char	*outfile;
}	t_path;

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	pipe[2];
}	t_fd;

typedef struct s_data
{
	t_args	args;
	t_path	path;
	t_cmd	cmd;
	t_fd	fd;
	pid_t	pid;
}	t_data;

void	check_argc(int argc);
void	get_initial_data(int argc, char **argv, char **envp, t_data *data);
void	get_initial_cmd_array(t_data *data);

void	make_infile_to_standard_input(t_data *data);

void	execute_cmd(char *cmd, t_data *data);

void	open_file(char *file_path, int file_type, t_data *data);
void	change_fd(int fd_to_change, int target_fd, t_data *data);
void	close_fd(int fd_to_close, t_data *data);
void	get_pipe_fd(t_data *data);
void	produce_child_process(t_data *data);
void	wait_child_process(pid_t pid, t_data *data);

void	execute_error_process(int error_number, t_data *data);

void	free_every_mallocated_data(t_data *data);
void	free_2d_array(char **array);

void	print_2d_array(char **array);

#endif
