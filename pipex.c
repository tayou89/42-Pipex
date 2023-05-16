/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:32:18 by tayou             #+#    #+#             */
/*   Updated: 2023/05/17 00:55:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_argc(argc);
	get_initial_data(argv, envp, &data);
	open_file_and_change_fd(data.initial.file_1, STDOUT);
	produce_child_processs(&data);
	execute_cmd(data.initial.cmd_1, &data);
	return (0);
}

void	produce_child_process(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		execute_error_process(FORK_ERROR, data);
	if (pid == 0)
	{
		execute_cmd(data->cmd.array[0], data);



