/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:38:01 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 21:41:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_child_process(pid_t pid, t_data *data)
{
	int	wait_return;

	wait_return = waitpid(pid, (void *) 0, 0);
	if (wait_return == -1)
		execute_error_process(WAIT_ERROR, data);
}
