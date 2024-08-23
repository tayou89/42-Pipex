/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_in_parallel.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:29:56 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:30:07 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd_in_parallel(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd.count)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			perror("fork error");
		if (data->pid[i] == 0)
			execute_child_process(i, data);
		i++;
	}
	execute_parent_process(data);
}
