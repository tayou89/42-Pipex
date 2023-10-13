/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:41:07 by tayou             #+#    #+#             */
/*   Updated: 2023/06/01 11:06:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_former_pipe_read_fd_to_standard_input(int index, t_data *data);
void	make_current_pipe_write_fd_to_standard_output(int index, t_data *data);
void	make_outfile_fd_to_standard_out(t_data *data);
void	close_and_free_all_then_exit(int index, int exit_number, t_data *data);

void	execute_child_process(int index, t_data *data)
{
	if (index == 0 && data->flag.heredoc_exist == FALSE
		&& data->flag.open_infile == FAIL)
		close_and_free_all_then_exit(index, 1, data);
	check_cmd_accessibility(data->cmd.array[data->child_number], data);
	if (data->flag.find_accessible_path == FAIL)
		close_and_free_all_then_exit(index, 127, data);
	if (index > 0)
		make_former_pipe_read_fd_to_standard_input(index, data);
	if (index < data->cmd.count - 1)
		make_current_pipe_write_fd_to_standard_output(index, data);
	if (index == data->cmd.count - 1)
		make_outfile_fd_to_standard_out(data);
	execve(data->cmd.path, data->cmd.split_array, data->args.envp);
}

void	make_former_pipe_read_fd_to_standard_input(int index, t_data *data)
{
	close_fd(data->fd.pipe[index - 1][WRITE]);
	if (data->flag.find_accessible_path == SUCCESS)
	{
		change_fd(data->fd.pipe[index - 1][READ], STDIN);
		close_fd(data->fd.pipe[index - 1][READ]);
	}
	else
		close_fd(data->fd.pipe[index - 1][READ]);
}

void	make_current_pipe_write_fd_to_standard_output(int index, t_data *data)
{
	close_fd(data->fd.pipe[index][READ]);
	if (data->flag.find_accessible_path == SUCCESS)
	{
		change_fd(data->fd.pipe[index][WRITE], STDOUT);
		close_fd(data->fd.pipe[index][WRITE]);
	}
	else
		close_fd(data->fd.pipe[index][WRITE]);
}

void	make_outfile_fd_to_standard_out(t_data *data)
{
	change_fd(data->fd.outfile, STDOUT);
	close_fd(data->fd.outfile);
}

void	close_and_free_all_then_exit(int index, int exit_number, t_data *data)
{
	if (index > 0)
	{
		close_fd(data->fd.pipe[index - 1][READ]);
		close_fd(data->fd.pipe[index - 1][WRITE]);
	}
	close_fd(data->fd.pipe[index][READ]);
	close_fd(data->fd.pipe[index][WRITE]);
	free_every_mallocated_data(data);
	exit(exit_number);
}
