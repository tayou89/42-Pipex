/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:26:47 by tayou             #+#    #+#             */
/*   Updated: 2023/05/24 21:41:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd_count(t_data *data);
void	malloc_initial_cmd_array(t_data *data);
void	fill_initial_cmd_array(t_data *data);

void	get_cmd_array(t_data *data)
{
	get_cmd_count(data);
	malloc_initial_cmd_array(data);
	fill_initial_cmd_array(data);
}

void	get_cmd_count(t_data *data)
{
	int	count;
	int	start_index;

	count = 0;
	data->cmd.start_index = 2;
	data->cmd.last_index = data->args.argc - 2;
	start_index = data->cmd.start_index;
	while (start_index <= data->cmd.last_index)
	{
		count++;
		start_index++;
	}
	data->cmd.count = count;
}

void	malloc_initial_cmd_array(t_data *data)
{
	data->cmd.array = \
		(char **) malloc(sizeof(char *) * (data->cmd.count + 1));
	if (data->cmd.array == (void *) 0)
		execute_error_process(MALLOC_ERROR, data);
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
			ft_strdup(data->args.argv[argv_index]);
		if (data->cmd.array[i] == (void *) 0)
			execute_error_process(MALLOC_ERROR, data);
		argv_index++;
		i++;
	}
	data->cmd.array[i] = (void *) 0;
}
