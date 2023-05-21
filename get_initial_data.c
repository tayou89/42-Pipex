/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:12:14 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 16:01:25 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_initial_data(int argc, char **argv, char **envp, t_data *data)
{
	data->initial.argc = argc;
	data->initial.argv = argv;
	data->initial.infile = argv[1];
	data->initial.outfile = argv[argc - 1];
	data->initial.envp = envp;
	data->cmd.array = (void *) 0;
	data->cmd.split_array = (void *) 0;
	data->cmd.directory = (void *) 0;
	data->cmd.path = (void *) 0;
	get_initial_cmd_array(data);
}
