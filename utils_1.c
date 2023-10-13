/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:37:24 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 22:37:13 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(char *file_path, int file_type, t_data *data)
{
	int	fd;

	fd = 0;
	if (file_type == INFILE)
	{
		fd = open(file_path, RDONLY);
		data->fd.infile = fd;
	}
	else if (file_type == OUTFILE)
	{
		fd = open(file_path, RDWR | CREAT | TRUNC, 0666);
		data->fd.outfile = fd;
	}
	if (fd == -1)
		execute_error_process(OPEN_ERROR, data);
}

void	change_fd(int fd_to_change, int target_fd, t_data *data)
{
	int dup_return;

	dup_return = dup2(fd_to_change, target_fd);
	if (dup_return == -1)
		execute_error_process(DUP_ERROR, data);
}

void	close_fd(int fd_to_close, t_data *data)
{
	int close_return;

	close_return = close(fd_to_close);
	if (close_return == -1)
		execute_error_process(CLOSE_ERROR, data);
}

void	get_pipe_fd(t_data *data)
{
	int	pipe_return;

	pipe_return = pipe(data->fd.pipe);
	if (pipe_return == -1)
		execute_error_process(PIPE_ERROR, data);
}

void	produce_child_process(t_data *data)
{
	data->pid = fork();
	if (data->pid == -1)
		execute_error_process(FORK_ERROR, data);
}
