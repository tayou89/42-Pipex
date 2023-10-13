/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:05:16 by tayou             #+#    #+#             */
/*   Updated: 2023/06/01 11:07:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	leaks(void)
{
	system("leaks pipex_bonus");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_argc(argc);
	check_heredoc_exist(argv, &data);
	make_initial_setting(argc, argv, envp, &data);
	execute_cmd_by_parallel_process(&data);
	free_every_mallocated_data(&data);
	atexit(leaks);
	return (0);
}
