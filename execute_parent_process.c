/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:37:20 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 21:00:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_every_child_process(t_data *data);

void	execute_parent_process(t_data *data)
{
	close_fd(data->fd.pipe[READ]);
	close_fd(data->fd.pipe[WRITE]);
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
