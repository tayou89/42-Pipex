/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:12:14 by tayou             #+#    #+#             */
/*   Updated: 2023/05/16 23:49:11 by tayou            ###   ########.fr       */
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
	data->cmd.array = (void *) 0;
	data->cmd.split_array = (void *) 0;
	data->cmd.directory = (void *) 0;
	data->cmd.path = (void *) 0;
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

	count = 0;
	data->cmd.start_index = 2;
	data->cmd.last_index = data->initial.argc - 2;
	while (data->cmd.start_index <= data->cmd.last_index)
		count++;
	data->cmd.count = count;
}

void	malloc_initial_cmd_array(t_data *data)
{
	data->cmd.array = \
		(char **) malloc(sizeof(char *) * (data->cmd.count + 1));
	if (data->cmd.array == (void *) 0)
	{
		print_error_message(MALLOC_ERROR);
		exit(1);
	}
}

void	fill_initial_cmd_array(t_data *data)
{
	int	i;
	int	argv_index;

	argv_index = data->cmd.start_index;
	i = 0;
	while (i < data->cmd.count)
	{
		data->cmd.array[i] = \
			ft_strdup(data->initial.argv[argv_index]);
		if (data->cmd.array[i] == (void *) 0)
			execute_error_process(MALLOC_ERROR, data);
		argv_index++;
		i++;
	}
}
