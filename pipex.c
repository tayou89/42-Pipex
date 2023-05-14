/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:32:18 by tayou             #+#    #+#             */
/*   Updated: 2023/05/14 23:31:11 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_argc(argc);
	get_initial_data(argv, envp, &data);
	produce_child_processs(&data);
	make_file_1_to_standard_input(&data);
	execute_cmd(data.initial.cmd_1, &data);
	return (0);
}
