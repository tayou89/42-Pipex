/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:24:15 by tayou             #+#    #+#             */
/*   Updated: 2023/05/15 00:13:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_every_mallocated_data(t_data *data)
{
	if (data->array.cmd != (void *) 0)
		free_2d_array(data->array.cmd

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

void	print_error_message(char *error_message)
{
	if (error_message == (void *) 0)
		return ;
	ft_printf("%s\n", error_message);
}
