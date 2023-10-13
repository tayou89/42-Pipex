/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:03:54 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:33:58 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_every_mallocated_data(t_data *data)
{
	if (data->cmd.array != (void *) 0)
		free_2d_array((void **) data->cmd.array);
	if (data->cmd.split_array != (void *) 0)
		free_2d_array((void **) data->cmd.split_array);
	if (data->cmd.directory != (void *) 0)
		free_2d_array((void **) data->cmd.directory);
	if (data->fd.pipe != (void *) 0)
		free_2d_array((void **) data->fd.pipe);
	if (data->cmd.path != (void *) 0)
		free_1d_array((void *) data->cmd.path);
	if (data->pid != (void *) 0)
		free_1d_array((void *) data->pid);
}

void	free_2d_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		free_1d_array((void *) array[i]);
		i++;
	}
	free(array);
	array = (void *) 0;
}

void	free_1d_array(void *array)
{
	free(array);
	array = (void *) 0;
}
