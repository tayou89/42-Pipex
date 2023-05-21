/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:31:07 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 17:34:23 by tayou            ###   ########.fr       */
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
# define FILE_MODE		0666
# define BUFFER_SIZE	10;

# define STDIN			0
# define STDOUT			1

# define FILE_OK		0
# define EXEC_OK		1

# define READ			0
# define WRITE			1

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

typedef struct s_initial
{
	int		argc;
	char	**argv;
	char	*infile;
	char	*outfile;
	char	**envp;
}	t_initial;

typedef struct s_fd
{
	int	file_1;
	int	pipe[2];
}	t_fd;

typedef struct s_data
{
	t_initial	initial;
	t_cmd		cmd;
	t_fd		fd;
	pid_t		pid;
	int			child_number;
	int			stat_loc;
	int			output_line_count;
}	t_data;

void	check_argc(int argc);
void	get_initial_data(int argc, char **argv, char **envp, t_data *data);
void	get_initial_cmd_array(t_data *data);
void	make_file_1_to_standard_input(t_data *data);
void	execute_cmd(char *cmd, t_data *data);

void	free_every_mallocated_data(t_data *data);
void	free_2d_array(char **array);

void	print_2d_array(char **array);

#endif
