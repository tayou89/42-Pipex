/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:34:57 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 20:55:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_initial_data(int argc, char **argv, char **envp, t_data *data);
void	initialize_mallocible_data(t_data *data);
void	make_infile_fd_to_standard_input(t_data *data);
void	malloc_pid_array(t_data *data);

void	make_initial_setting(int argc, char **argv, char **envp, t_data *data)
{
	set_initial_data(argc, argv, envp, data);
	initialize_mallocible_data(data);
	get_cmd_array(data);
	get_cmd_directory_array(data);
	malloc_pid_array(data);
	open_files(data);
	if (data->flag.open_infile == SUCCESS)
		make_infile_fd_to_standard_input(data);
}

void	set_initial_data(int argc, char **argv, char **envp, t_data *data)
{
	initialize_mallocible_data(data);
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.envp = envp;
	data->path.infile = argv[1];
	data->path.outfile = argv[argc - 1];
	data->flag.open_infile = FAIL;
	data->flag.open_outfile = FAIL;
	data->flag.find_accessible_path = FAIL;
	data->child_number = 0;
}

void	initialize_mallocible_data(t_data *data)
{
	data->cmd.array = (void *) 0;
	data->cmd.split_array = (void *) 0;
	data->cmd.directory = (void *) 0;
	data->cmd.path = (void *) 0;
	data->pid = (void *) 0;
}

void	make_infile_fd_to_standard_input(t_data *data)
{
	int	dup2_return;

	dup2_return = dup2(data->fd.infile, STDIN);
	if (dup2_return == -1)
		print_error_message(DUP_ERROR);
}

void	malloc_pid_array(t_data *data)
{
	data->pid = (pid_t *) malloc(sizeof(pid_t) * data->cmd.count);
	if (data->pid == (void *) 0)
		execute_error_process(MALLOC_ERROR, 1, data);
}
