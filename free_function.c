/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:23:39 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 23:18:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_every_mallocated_data(t_data *data)
{
	if (data->cmd.array != (void *) 0)
		free_2d_array(data->cmd.array);
	if (data->cmd.split_array != (void *) 0)
		free_2d_array(data->cmd.split_array);
	if (data->cmd.directory != (void *) 0)
		free_2d_array(data->cmd.directory);
	if (data->cmd.path != (void *) 0)
	{
		free(data->cmd.path);
		data->cmd.path = (void *) 0;
	}
	if (data->pid != (void *) 0)
	{
		free(data->pid);
		data->pid = (void *) 0;
	}
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		free(array[i]);
		array[i] = (void *) 0;
		i++;
	}
	free(array);
	array = (void *) 0;
}
