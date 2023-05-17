/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:32:18 by tayou             #+#    #+#             */
/*   Updated: 2023/05/17 23:49:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_argc(argc);
	get_initial_data(argv, envp, &data);
	open_file(&data);
	if (data.fd.file_1 != -1)
		change_fd(data.fd.file_1, STDIN, &data);
	produce_child_processs(&data);
	if (data.pid != 0)
		execute_parent_process(data);
	else if (data.pid == 0)
		execute_child_process(data);
	change_fd(data.fd.pipe[READ], STDOUT, &data);
	open_file_2(&data);
	return (0);
}

void	open_file_1(t_data *data)
{
	data->fd.file_2 = \
		open(data->initial.file_2, RDWR | CREAT | TRUNC, FILE_MODE);
	if (data->fd.file_2 == -1)
		execute_error_process(OPEN_ERROR, data);
	data->fd.file_1 = open(data->initial.file_1, RDONLY);
	if (data->fd.file_1 == -1)
		execute_error_process(OPEN_ERROR, data);
}

void	open_file_2(t_data *data)
{
	data->fd.file_2 = open(data->initial.file_2, RDWR | CREAT

void	change_fd(int original_fd, int fd_to_change, t_data *data)
{
	int	dup2_return;
	int	close_return;

	dup2_return = dup2(original_fd, fd_to_change);
	if (dup2_return == -1)
		execute_error_process(DUP_ERROR, data);
	close_return = close(original_fd);
	if (close_return == -1)
		execute_error_process(CLOSE_ERROR, data);
}

void	produce_child_process(t_data *data)
{
	int	pipe_return;	

	data->child_number = 0;
	pipe_return = pipe(data->fd.pipe[2]);
	if (pipe_return == -1)
		execute_error_process(PIPE_ERROR, data);
	data->pid = fork();
	if (data->pid == -1)
		execute_error_process(FORK_ERROR, data);
}

void	execute_parent_process(t_data *data)
{
	data->child_number++;
	data->pid = fork();
	if (data->pid == -1)
		execute_error_process(FORK_ERROR, data);
	close(data->fd.pipe[READ]);
	close(data->fd.pipe[WRITE]);
	if (waitpid(data->pid, &(data->stat_loc), 0) == -1)
		execute_error_process(WAIT_ERROR, data);
}

void	execute_child_process(t_data *data)
{
	int	close_return;

	if (data->child_number == 0)
	{
		close_return = close(data->fd.pipe[READ]);
		if (close_return == -1)
			execute_error_process(CLOSE_ERROR, data);
	}
	else if (data->child_number == 1)
	{
		close(data->fd.pipe[WRITE]);
		if (close_return == -1)
			execute_error_process(CLOSE_ERROR, data);
	}
	execute_cmd(data->cmd.array[child_number], data);
}
