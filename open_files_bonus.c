/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:05:03 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 23:27:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_heredoc(t_data *data);
void	find_valid_heredoc_path_to_open(t_data *data);
void	open_infile(t_data *data);
void	open_outfile(t_data *data);

void	open_files(t_data *data)
{
	if (data->flag.heredoc_exist == TRUE)
		open_heredoc(data);
	else
		open_infile(data);
	open_outfile(data);
}

void	open_heredoc(t_data *data)
{
	data->fd.heredoc = open(data->path.heredoc, \
			RDWR | CREAT | TRUNC, IRUSR | IWUSR | IRGRP | IROTH);
	if (data->fd.heredoc == -1)
		find_valid_heredoc_path_to_open(data);
}

void	find_valid_heredoc_path_to_open(t_data *data)
{
	char	suffix[2];
	char	*new_path;

	data->path.heredoc = ft_strdup(data->path.heredoc);
	if (data->path.heredoc == (void *) 0)
		execute_error_process(MALLOC_ERROR, 1, data);
	suffix[0] = 'a';
	suffix[1] = '\0';
	new_path = (void *) 0;
	while (data->fd.heredoc == -1)
	{
		new_path = ft_strjoin(data->path.heredoc, suffix);
		if (new_path == (void *) 0)
			execute_error_process(MALLOC_ERROR, 1, data);
		data->fd.heredoc = open(data->path.heredoc, \
				RDWR | CREAT | TRUNC, IRUSR | IWUSR | IRGRP | IROTH);
		if (data->fd.heredoc == -1)
			free_1d_array(new_path);
		if (suffix[0] == 'z')
			suffix[0] = 'a';
		else
			suffix[0]++;
	}
	free_1d_array(data->path.heredoc);
	data->path.heredoc = new_path;
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
	if (data->flag.heredoc_exist == TRUE)
		data->fd.outfile = open(data->path.outfile, \
			RDWR | CREAT | APPEND, IRUSR | IWUSR | IRGRP | IROTH);
	else
		data->fd.outfile = open(data->path.outfile, \
			RDWR | CREAT | TRUNC, IRUSR | IWUSR | IRGRP | IROTH);
	if (data->fd.outfile == -1)
		execute_error_process(OPEN_ERROR, 1, data);
	data->flag.open_outfile = SUCCESS;
}
