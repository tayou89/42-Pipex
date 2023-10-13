/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:32:18 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 22:57:48 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile_to_standard_input(t_data *data);
void	execute_parent_process(t_data *data);
void	execute_child_process(t_data *data);
void	open_outfile_to_standard_output(t_data *data);

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_argc(argc);
	get_initial_data(argc, argv, envp, &data);
	open_infile_to_standard_input(&data);
	get_pipe_fd(&data);
	produce_child_process(&data);
	if (data.pid != 0)
		execute_parent_process(&data);
	else if (data.pid == 0)
		execute_child_process(&data);
	free_every_mallocated_data(&data);
	return (0);
}

void	open_infile_to_standard_input(t_data *data)
{
	open_file(data->path.infile, INFILE, data);
	change_fd(data->fd.infile, STDIN, data);
	close_fd(data->fd.infile, data);
}

void	execute_parent_process(t_data *data)
{
	close_fd(data->fd.pipe[READ], data);
	change_fd(data->fd.pipe[WRITE], STDOUT, data);
	close_fd(data->fd.pipe[WRITE], data);
	execute_cmd(data->cmd.array[0], data);
	wait_child_process(data->pid, data);
}

void	execute_child_process(t_data *data)
{
	open_outfile_to_standard_output(data);
	close_fd(data->fd.pipe[WRITE], data);
	change_fd(data->fd.pipe[READ], STDIN, data);
	close_fd(data->fd.pipe[READ], data);
	execute_cmd(data->cmd.array[1], data);
}

void	open_outfile_to_standard_output(t_data *data)
{
	open_file(data->path.outfile, OUTFILE, data);
	change_fd(data->fd.outfile, STDOUT, data);
	close_fd(data->fd.outfile, data);
}
