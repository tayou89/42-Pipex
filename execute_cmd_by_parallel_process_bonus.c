/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_by_parallel_process_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:03:11 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 23:13:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_parent_process(int index, t_data *data);

void	execute_cmd_by_parallel_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd.count)
	{
		if (i < data->cmd.count - 1)
			get_pipe_fd(i, data);
		produce_child_process(i, data);
		if (data->pid[i] > 0)
			execute_parent_process(i, data);
		else if (data->pid[i] == 0)
			execute_child_process(i, data);
		i++;
	}
}

void	execute_parent_process(int index, t_data *data)
{
	if (index > 0)
	{
		close_fd(data->fd.pipe[index - 1][READ]);
		close_fd(data->fd.pipe[index - 1][WRITE]);
	}
	data->child_number++;
	if (index == data->cmd.count - 1)
		wait_every_child_process(data);
}
