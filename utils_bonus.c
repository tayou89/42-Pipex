/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:05:30 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 23:51:55 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	produce_child_process(int index, t_data *data)
{
	data->pid[index] = fork();
	if (data->pid[index] == -1)
		execute_error_process(FORK_ERROR, 1, data);
}

void	get_pipe_fd(int index, t_data *data)
{
	int	pipe_return;

	pipe_return = pipe(data->fd.pipe[index]);
	if (pipe_return == -1)
		execute_error_process(PIPE_ERROR, 1, data);
}

void	change_fd(int fd_to_change, int target_fd)
{
	int	dup_return;

	dup_return = dup2(fd_to_change, target_fd);
	if (dup_return == -1)
		print_error_message(DUP_ERROR);
}

void	close_fd(int fd_to_close)
{
	int	close_return;

	close_return = close(fd_to_close);
	if (close_return == -1)
		print_error_message(CLOSE_ERROR);
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
