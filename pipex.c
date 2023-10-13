/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:32:18 by tayou             #+#    #+#             */
/*   Updated: 2023/05/25 00:18:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_parent_process(t_data *data);
void	open_infile_to_standard_input(t_data *data);
void	execute_child_process(t_data *data);
void	open_outfile_to_standard_output(t_data *data);

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_argc(argc);
	get_initial_data(argc, argv, envp, &data);
	open_infile_to_standard_input(&data);
	open_outfile_to_standard_output(&data);
	get_pipe_fd(&data);
	produce_child_process(&data);
	if (data.pid != 0)
		execute_parent_process(&data);
	else if (data.pid == 0)
		execute_child_process(&data);
	free_every_mallocated_data(&data);
	return (0);
}

void	execute_child_process(t_data *data)
{
	close_fd(data->fd.pipe[READ], data);
	check_cmd_accessibility(data->cmd.array[0], data);
	if (data->flag.open_infile == SUCCESS
		&& data->flag.find_accessible_path == SUCCESS)
	{
		change_fd(data->fd.pipe[WRITE], STDOUT, data);
		close_fd(data->fd.pipe[WRITE], data);
		execve(data->cmd.path, data->cmd.split_array, data->args.envp);
	}
	else
		close_fd(data->fd.pipe[WRITE], data);
}

void	open_infile_to_standard_input(t_data *data)
{
	open_file(data->path.infile, INFILE, data);
	if (data->flag.open_infile == SUCCESS)
	{
		change_fd(data->fd.infile, STDIN, data);
		close_fd(data->fd.infile, data);
	}
}

void	execute_parent_process(t_data *data)
{
	wait_child_process(data->pid, data);
	close_fd(data->fd.pipe[WRITE], data);
	check_cmd_accessibility(data->cmd.array[1], data);
	if (data->flag.open_outfile == SUCCESS
		&& data->flag.find_accessible_path == SUCCESS)
	{
		change_fd(data->fd.outfile, STDOUT, data);
		close_fd(data->fd.outfile, data);
		change_fd(data->fd.pipe[READ], STDIN, data);
		close_fd(data->fd.pipe[READ], data);
		execve(data->cmd.path, data->cmd.split_array, data->args.envp);
	}
	else
		close_fd(data->fd.pipe[READ], data);
}

void	open_outfile_to_standard_output(t_data *data)
{
	open_file(data->path.outfile, OUTFILE, data);
}
