/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:06:23 by tayou             #+#    #+#             */
/*   Updated: 2023/06/01 11:13:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define RDONLY			0
# define WRONLY			1
# define RDWR			2
# define APPEND			8
# define CREAT			512
# define TRUNC			1024

# define IRUSR			256
# define IWUSR			128
# define IRGRP			32
# define IROTH			4

# define STDIN			0
# define STDOUT			1

# define FILE_OK		0
# define EXEC_OK		1

# define READ			0
# define WRITE			1

# define INFILE			0
# define OUTFILE		1

# define SUCCESS		1
# define FAIL			0

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
# define STOP_ERROR		20

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
	char	*heredoc;
}	t_path;

typedef struct s_fd
{
	int	heredoc;
	int	infile;
	int	outfile;
	int	**pipe;
}	t_fd;

typedef struct s_flag
{
	int	open_infile;
	int	open_outfile;
	int	find_accessible_path;
	int	heredoc_exist;
	int	same_with_stop_string;
}	t_flag;

typedef struct s_data
{
	t_args	args;
	t_path	path;
	t_cmd	cmd;
	t_fd	fd;
	t_flag	flag;
	pid_t	*pid;
	int		child_number;
	char	*stop_string;
}	t_data;

void	check_argc(int argc);
void	check_heredoc_exist(char **argv, t_data *data);

void	make_initial_setting(int argc, char **argv, char **envp, t_data *data);
void	get_cmd_array(t_data *data);
void	get_cmd_directory_array(t_data *data);
void	open_files(t_data *data);
void	read_line_and_write_to_heredoc(t_data *data);

void	execute_cmd_by_parallel_process(t_data *data);
void	execute_child_process(int index, t_data *data);
void	check_cmd_accessibility(char *cmd, t_data *data);

void	change_fd(int fd_to_change, int target_fd);
void	close_fd(int fd_to_close);
void	get_pipe_fd(int index, t_data *data);
void	produce_child_process(int index, t_data *data);
void	wait_every_child_process(t_data *data);

void	execute_error_process(int error_number, int exit_number, t_data *data);
void	print_error_message(int error_number);

void	free_every_mallocated_data(t_data *data);
void	free_2d_array(void **array);
void	free_1d_array(void *array);

#endif
