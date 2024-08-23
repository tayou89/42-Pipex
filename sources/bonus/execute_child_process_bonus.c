/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:41:07 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:10:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	change_left_pipe_fd(int index, t_data *data);
void	change_right_pipe_fd(int index, t_data *data);

void	execute_child_process(int index, t_data *data)
{
	if (index == 0)
		open_file(data->path.infile, INFILE, data);
	if (index == data->cmd.count - 1)
		open_file(data->path.outfile, OUTFILE, data);
	get_cmd_path(data->cmd.array[index], data);
	if (index == 0)
		change_fd(data->fd.file, STDIN);
	if (index == data->cmd.count - 1)
		change_fd(data->fd.file, STDOUT);
	change_left_pipe_fd(index, data);
	change_right_pipe_fd(index, data);
	if (execve(data->cmd.path, data->cmd.split_array, data->args.envp) == -1)
	{
		if (data->cmd.split_array[0][0] == '\0')
			perror(data->cmd.array[index]);
		else
			perror(data->cmd.path);
		exit(127);
	}
}

void	change_left_pipe_fd(int index, t_data *data)
{
	if (index == 0)
		return ;
	close_fd(data->fd.pipe[index - 1][WRITE]);
	change_fd(data->fd.pipe[index - 1][READ], STDIN);
}

void	change_right_pipe_fd(int index, t_data *data)
{
	if (index == data->cmd.count - 1)
		return ;
	close_fd(data->fd.pipe[index][READ]);
	change_fd(data->fd.pipe[index][WRITE], STDOUT);
}
