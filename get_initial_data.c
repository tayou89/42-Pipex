/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:12:14 by tayou             #+#    #+#             */
/*   Updated: 2023/05/24 22:31:35 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_initial_data(int argc, char **argv, char **envp, t_data *data)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.envp = envp;
	data->path.infile = argv[1];
	data->path.outfile = argv[argc - 1];
	data->cmd.array = (void *) 0;
	data->cmd.split_array = (void *) 0;
	data->cmd.directory = (void *) 0;
	data->cmd.path = (void *) 0;
	data->flag.open_infile = FAIL;
	data->flag.open_outfile = FAIL;
	data->flag.find_accessible_path = FAIL;
	get_cmd_array(data);
	get_cmd_directory_array(data);
}
