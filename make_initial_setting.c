/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:34:57 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 20:49:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_initial_data(int argc, char **argv, char **envp, t_data *data);
void	initialize_mallocible_data(t_data *data);
void	malloc_pid_array(t_data *data);

void	make_initial_setting(int argc, char **argv, char **envp, t_data *data)
{
	set_initial_data(argc, argv, envp, data);
	initialize_mallocible_data(data);
	get_cmd_array(data);
	get_cmd_directory_array(data);
	malloc_pid_array(data);
}

void	set_initial_data(int argc, char **argv, char **envp, t_data *data)
{
	initialize_mallocible_data(data);
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.envp = envp;
	data->path.infile = argv[1];
	data->path.outfile = argv[argc - 1];
}

void	initialize_mallocible_data(t_data *data)
{
	data->cmd.array = (void *) 0;
	data->cmd.split_array = (void *) 0;
	data->cmd.directory = (void *) 0;
	data->cmd.path = (void *) 0;
	data->pid = (void *) 0;
}

void	malloc_pid_array(t_data *data)
{
	data->pid = (pid_t *) malloc(sizeof(pid_t) * data->cmd.count);
	if (data->pid == (void *) 0)
		execute_error_process((void *) 0, 1, data);
}
