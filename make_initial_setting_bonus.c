/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_setting_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:04:46 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 23:50:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	set_initial_data(int argc, char **argv, char **envp, t_data *data);
void	initialize_mallocible_data(t_data *data);
void	make_file_fd_to_standard_input(int fd);
void	malloc_pid_and_pipe_array(t_data *data);

void	make_initial_setting(int argc, char **argv, char **envp, t_data *data)
{
	set_initial_data(argc, argv, envp, data);
	initialize_mallocible_data(data);
	get_cmd_array(data);
	get_cmd_directory_array(data);
	malloc_pid_and_pipe_array(data);
	open_files(data);
	if (data->flag.heredoc_exist == TRUE)
	{
		read_line_and_write_to_heredoc(data);
		data->fd.heredoc = open(data->path.heredoc, RDONLY);
		make_file_fd_to_standard_input(data->fd.heredoc);
	}
	else
	{
		if (data->flag.open_infile == SUCCESS)
			make_file_fd_to_standard_input(data->fd.infile);
	}
}

void	set_initial_data(int argc, char **argv, char **envp, t_data *data)
{
	initialize_mallocible_data(data);
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.envp = envp;
	data->child_number = 0;
	data->flag.open_infile = FAIL;
	data->flag.open_outfile = FAIL;
	data->flag.find_accessible_path = FAIL;
	data->flag.same_with_stop_string = FAIL;
	data->path.outfile = argv[argc - 1];
	if (data->flag.heredoc_exist == TRUE)
	{
		data->path.infile = (void *) 0;
		data->path.heredoc = "/tmp/heredoc_tmp";
		data->stop_string = argv[2];
	}
	else
	{
		data->path.infile = argv[1];
		data->path.heredoc = (void *) 0;
		data->stop_string = (void *) 0;
	}
}

void	initialize_mallocible_data(t_data *data)
{
	data->cmd.array = (void *) 0;
	data->cmd.split_array = (void *) 0;
	data->cmd.directory = (void *) 0;
	data->cmd.path = (void *) 0;
	data->pid = (void *) 0;
	data->fd.pipe = (void *) 0;
}

void	make_file_fd_to_standard_input(int fd)
{
	change_fd(fd, STDIN);
	close_fd(fd);
}

void	malloc_pid_and_pipe_array(t_data *data)
{
	int	i;

	data->pid = (pid_t *) malloc(sizeof(pid_t) * data->cmd.count);
	if (data->pid == (void *) 0)
		execute_error_process(MALLOC_ERROR, 1, data);
	data->fd.pipe = (int **) malloc(sizeof(int *) * (data->cmd.count));
	if (data->fd.pipe == (void *) 0)
		execute_error_process(MALLOC_ERROR, 1, data);
	data->fd.pipe[data->cmd.count - 1] = (void *) 0;
	i = 0;
	while (i + 1 < data->cmd.count)
	{
		data->fd.pipe[i] = (int *) malloc(sizeof(int) * 2);
		if (data->fd.pipe[i] == (void *) 0)
			execute_error_process(MALLOC_ERROR, 1, data);
		i++;
	}
}
