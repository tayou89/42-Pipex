/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_by_parallel_process.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:17:44 by tayou             #+#    #+#             */
/*   Updated: 2023/05/29 20:22:14 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_parent_process(t_data *data);
void	execute_child_process(t_data *data);
void	execute_first_child_process(t_data *data);
void	execute_second_child_process(t_data *data);

void	execute_cmd_by_parallel_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd.count)
	{
		produce_child_process(i, data);
		if (data->pid[i] == 0)
			execute_child_process(data);
		data->child_number++;
		i++;
	}
	execute_parent_process(data);
}

void	execute_parent_process(t_data *data)
{
	close_fd(data->fd.pipe[READ], data);
	close_fd(data->fd.pipe[WRITE], data);
	wait_every_child_process(data);
}

void	execute_child_process(t_data *data)
{
	if (data->child_number == 0)
		execute_first_child_process(data);
	else
		execute_second_child_process(data);
}

void	execute_first_child_process(t_data *data)
{
	close_fd(data->fd.pipe[READ], data);
	check_cmd_accessibility(data->cmd.array[data->child_number], data);
	if (data->flag.find_accessible_path == SUCCESS
		&& data->flag.open_infile == SUCCESS)
	{
		change_fd(data->fd.pipe[WRITE], STDOUT, data);
		close_fd(data->fd.pipe[WRITE], data);
		execve(data->cmd.path, data->cmd.split_array, data->args.envp);
	}
	else
	{
		close_fd(data->fd.pipe[WRITE], data);
		execute_error_process(CMD_ERROR, 127, data);
	}
}

void	execute_second_child_process(t_data *data)
{
	close_fd(data->fd.pipe[WRITE], data);
	check_cmd_accessibility(data->cmd.array[data->child_number], data);
	if (data->flag.find_accessible_path == SUCCESS)
	{
		change_fd(data->fd.pipe[READ], STDIN, data);
		close_fd(data->fd.pipe[READ], data);
		change_fd(data->fd.outfile, STDOUT, data);
		close_fd(data->fd.outfile, data);
		execve(data->cmd.path, data->cmd.split_array, data->args.envp);
	}
	else
	{
		close_fd(data->fd.pipe[READ], data);
		execute_error_process(CMD_ERROR, 127, data);
	}
}
