/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:24:15 by tayou             #+#    #+#             */
/*   Updated: 2023/05/29 17:21:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(t_data *data);
void	open_outfile(t_data *data);

void	open_files(t_data *data)
{
	open_infile(data);
	open_outfile(data);
}

void	open_infile(t_data *data)
{
	data->fd.infile = open(data->path.infile, RDONLY);
	if (data->fd.infile == -1)
	{
		print_error_message(OPEN_ERROR);
		return ;
	}
	data->flag.open_infile = SUCCESS;
}

void	open_outfile(t_data *data)
{
	data->fd.outfile = open(data->path.outfile, \
			RDWR | CREAT | TRUNC, IRUSR | IWUSR | IRGRP | IROTH);
	if (data->fd.outfile == -1)
		execute_error_process(OPEN_ERROR, 1, data);
	data->flag.open_outfile = SUCCESS;
}
