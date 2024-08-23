/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:31:07 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 23:18:36 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

# define RDONLY			0
# define RDWR			2
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
	int	file;
	int	pipe[2];
}	t_fd;

typedef struct s_data
{
	t_args	args;
	t_path	path;
	t_cmd	cmd;
	t_fd	fd;
	pid_t	*pid;
}	t_data;

void	check_argc(int argc);
void	make_initial_setting(int argc, char **argv, char **envp, t_data *data);
void	get_cmd_array(t_data *data);
void	get_cmd_directory_array(t_data *data);

void	execute_cmd_in_parallel(t_data *data);
void	execute_parent_process(t_data *data);
void	execute_child_process(int index, t_data *data);
void	get_cmd_path(char *cmd, t_data *data);

void	change_fd(int fd_to_change, int target_fd);
void	close_fd(int fd_to_close);
void	get_pipe_fd(t_data *data);
void	open_file(char *file_path, int file_type, t_data *data);
void	execute_error_process(char *error, int exit_number, t_data *data);

void	free_every_mallocated_data(t_data *data);
void	free_2d_array(char **array);

#endif
