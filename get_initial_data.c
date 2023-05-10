/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:12:14 by tayou             #+#    #+#             */
/*   Updated: 2023/05/11 00:27:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_initial_data(char **argv, char **envp, t_data *data)
{
	data->initial.file_1 = argv[1];
	data->initial.cmd_1 = argv[2];
	data->initial.cmd_2 = argv[3];
	data->initial.file_2 = argv[4];
	data->initial.envp = envp;
	data->array.cmd = (void *) 0;
	data->array.cmd_directory = (void *) 0;
}
