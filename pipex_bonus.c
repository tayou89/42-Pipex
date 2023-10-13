/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:05:16 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 23:27:19 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_heredoc_exist(argv, &data);
	check_argc(argc, &data);
	make_initial_setting(argc, argv, envp, &data);
	execute_cmd_in_parallel(&data);
	free_every_mallocated_data(&data);
	return (0);
}
