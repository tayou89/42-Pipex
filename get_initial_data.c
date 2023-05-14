/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:12:14 by tayou             #+#    #+#             */
/*   Updated: 2023/05/15 00:12:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_initial_data(int argc, char **argv, char **envp, t_data *data)
{
	get_pipe_fd(data);
	data->initial.argc = argc;
	data->initial.argv = argv;
	data->initial.file_1 = argv[1];
	data->initial.file_2 = argv[argc - 1];
	data->initial.envp = envp;
	data->array.cmd = (void *) 0;
	data->array.cmd_directory = (void *) 0;
	get_initial_cmd_array(data);
}

void	get_pipe_fd(t_data *data)
{
	int	pipe_return;

	pipe_return = pipe(data->fd.pipe);
	if (pipe_return == -1)
	{
		ft_printf("Pipe function is failed.\n");
		exit(1);
	}
}

void	get_initial_cmd_array(t_data *data)
{
	get_cmd_count(data);
	malloc_initial_cmd_array(data);
	fill_initial_cmd_array(data);
}

void	get_cmd_count(t_data *data)
{
	int	count;
	int	cmd_start_index;
	int	cmd_last_index;

	count = 0;
	data->initial.cmd.start_index = 2;
	data->initial.cmd.last_index = data->initial.argc - 2;
	while (cmd_start_index <= cmd_last_index)
		count++;
	data->initial.cmd.count = count;
}

void	malloc_initial_cmd_array(t_data *data)
{
	data->initial.cmd.array = \
		(char **) malloc(sizeof(char *) * (data->initial.cmd.count + 1));
	if (data->initial.cmd.array == (void *) 0)
	{
		print_error_message(data->message.malloc_error);
		exit(1);
	}
}

void	fill_initial_cmd_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->initial.cmd_count)
	{
		data->initial.cmd[i] = \
			ft_strdup(data->initial.argv[data->initial.cmd.start_index);
		if (data->initial.cmd[i] == (void *) 0)
		{
			print_error_message(data->message.malloc_error);
			free_every_mallocated_data(data);
			exit(1);
		}
	}
}
