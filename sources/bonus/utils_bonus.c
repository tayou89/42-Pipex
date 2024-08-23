/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:05:30 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:35:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_pipe_fd(int index, t_data *data)
{
	int	pipe_return;

	pipe_return = pipe(data->fd.pipe[index]);
	if (pipe_return == -1)
		perror("pipe error");
}

void	change_fd(int fd_to_change, int target_fd)
{
	int	dup_return;

	dup_return = dup2(fd_to_change, target_fd);
	if (dup_return == -1)
		perror("dup error");
	close_fd(fd_to_change);
}

void	close_fd(int fd_to_close)
{
	int	close_return;

	close_return = close(fd_to_close);
	if (close_return == -1)
		perror("close error");
}

void	open_file(char *file_path, int file_type, t_data *data)
{
	if (file_type == INFILE)
		data->fd.file = open(file_path, O_RDONLY);
	else if (file_type == OUTFILE)
	{
		if (data->flag.heredoc_exist == TRUE)
			data->fd.file = open(file_path, \
				RDWR | CREAT | APPEND, IRUSR | IWUSR | IRGRP | IROTH);
		else
			data->fd.file = open(file_path, \
				RDWR | CREAT | TRUNC, IRUSR | IWUSR | IRGRP | IROTH);
	}
	if (data->fd.file == -1)
		execute_error_process(file_path, 1, data);
}

void	execute_error_process(char *error, int exit_number, t_data *data)
{
	perror(error);
	free_every_mallocated_data(data);
	exit(exit_number);
}
