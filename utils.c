/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:59:55 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 23:51:21 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	produce_child_process(int index, t_data *data)
{
	data->pid[index] = fork();
	if (data->pid[index] == -1)
		execute_error_process(FORK_ERROR, 1, data);
}

void	change_fd(int fd_to_change, int target_fd, t_data *data)
{
	int	dup_return;

	dup_return = dup2(fd_to_change, target_fd);
	if (dup_return == -1)
		execute_error_process(DUP_ERROR, 1, data);
}

void	close_fd(int fd_to_close, t_data *data)
{
	int	close_return;

	close_return = close(fd_to_close);
	if (close_return == -1)
		execute_error_process(CLOSE_ERROR, 1, data);
}

void	get_pipe_fd(t_data *data)
{
	int	pipe_return;

	pipe_return = pipe(data->fd.pipe);
	if (pipe_return == -1)
		execute_error_process(PIPE_ERROR, 1, data);
}

void	wait_every_child_process(t_data *data)
{
	int	wait_return;
	int	i;

	if (data->pid == (void *) 0)
		return ;
	i = 0;
	while (i < data->cmd.count)
	{
		wait_return = waitpid(data->pid[i], (void *) 0, 0);
		if (wait_return == -1)
			execute_error_process(WAIT_ERROR, 1, data);
		i++;
	}
}
