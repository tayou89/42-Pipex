/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file_1_to_standard_input.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:12:51 by tayou             #+#    #+#             */
/*   Updated: 2023/05/11 00:28:25 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file_1_and_get_fd(t_data *data);
void	change_file_1_fd_to_standard_input(t_data *data);

void	make_file_1_to_standard_input(t_data *data)
{
	open_file_1_and_get_fd(data);
	change_file_1_fd_to_standard_input(data);
}

void	open_file_1_and_get_fd(t_data *data)
{
	data->fd.file_1 = open(data->initial.file_1, RDONLY);
	if (data->fd.file_1 < 0)
	{
		ft_printf("Error.\nFail to open file_1.\n");
		exit(0);
	}
}

void	change_file_1_fd_to_standard_input(t_data *data)
{
	data->fd.new_file_1 = dup2(data->fd.file_1, STDIN);
	if (data->fd.new_file_1 == -1)
	{
		ft_printf("Error.\nDup2 function is failed.\n");
		exit(1);
	}
}
