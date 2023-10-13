/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent_process_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:10:03 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 21:00:47 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_every_child_process(t_data *data);

void	execute_parent_process(int index, t_data *data)
{
	if (index > 0)
	{
		close_fd(data->fd.pipe[index - 1][READ]);
		close_fd(data->fd.pipe[index - 1][WRITE]);
	}
	if (index == data->cmd.count - 1)
		wait_every_child_process(data);
}

void	wait_every_child_process(t_data *data)
{
	int	wait_return;
	int	i;

	i = 0;
	while (i < data->cmd.count)
	{
		wait_return = waitpid(data->pid[i], (void *) 0, 0);
		if (wait_return == -1)
			execute_error_process((void *) 0, 1, data);
		i++;
	}
}
