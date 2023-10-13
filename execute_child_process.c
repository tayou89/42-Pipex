/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:50:32 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:58:27 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_child_process(int index, t_data *data);
void	execute_second_child_process(int index, t_data *data);

void	execute_child_process(int index, t_data *data)
{
	if (index == 0)
		execute_first_child_process(index, data);
	else if (index == 1)
		execute_second_child_process(index, data);
}

void	execute_first_child_process(int index, t_data *data)
{
	open_file(data->path.infile, INFILE, data);
	get_cmd_path(data->cmd.array[index], data);
	close_fd(data->fd.pipe[READ]);
	change_fd(data->fd.file, STDIN);
	change_fd(data->fd.pipe[WRITE], STDOUT);
	if (execve(data->cmd.path, data->cmd.split_array, data->args.envp) == -1)
	{
		if (data->cmd.split_array[0][0] == '\0')
			perror(data->cmd.array[index]);
		else
			perror(data->cmd.path);
		exit(127);
	}
}

void	execute_second_child_process(int index, t_data *data)
{
	open_file(data->path.outfile, OUTFILE, data);
	get_cmd_path(data->cmd.array[index], data);
	close_fd(data->fd.pipe[WRITE]);
	change_fd(data->fd.file, STDOUT);
	change_fd(data->fd.pipe[READ], STDIN);
	if (execve(data->cmd.path, data->cmd.split_array, data->args.envp) == -1)
	{
		if (data->cmd.split_array[0][0] == '\0')
			perror(data->cmd.array[index]);
		else
			perror(data->cmd.path);
		exit(127);
	}
}
