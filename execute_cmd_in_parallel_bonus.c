/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_in_parallel_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:30:18 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:30:28 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_cmd_in_parallel(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd.count)
	{
		if (i < data->cmd.count - 1)
			get_pipe_fd(i, data);
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			perror("fork error");
		if (data->pid[i] > 0)
			execute_parent_process(i, data);
		else if (data->pid[i] == 0)
			execute_child_process(i, data);
		i++;
	}
}
