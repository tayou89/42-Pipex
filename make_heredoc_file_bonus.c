/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:55:42 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:22:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_heredoc_file(t_data *data);
void	read_line_and_write_to_heredoc(t_data *data);
int		check_line_same_with_stop_string(char *line, t_data *data);

void	make_heredoc_file(t_data *data)
{
	open_heredoc_file(data);
	read_line_and_write_to_heredoc(data);
}

void	open_heredoc_file(t_data *data)
{
	data->fd.file = open(data->path.infile, \
		RDWR | CREAT | TRUNC, IRUSR | IWUSR | IRGRP | IROTH);
	if (data->fd.file == -1)
		execute_error_process(data->path.infile, 1, data);
}

void	read_line_and_write_to_heredoc(t_data *data)
{
	char	*line;

	write(1, "heredoc> ", 9);
	line = get_next_line(0);
	if (line == (void *) 0)
		execute_error_process("read_error", 1, data);
	while (check_line_same_with_stop_string(line, data) == FALSE)
	{
		write(data->fd.file, line, ft_strlen(line));
		free_1d_array(line);
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (line == (void *) 0)
			execute_error_process("read_error", 1, data);
	}
	free_1d_array(line);
	close_fd(data->fd.file);
}

int	check_line_same_with_stop_string(char *line, t_data *data)
{
	char	*stop_string;
	int		strncmp_return;

	stop_string = data->stop_string;
	strncmp_return = ft_strncmp(line, stop_string, ft_strlen(stop_string));
	if (strncmp_return == 0 && line[ft_strlen(stop_string)] == '\n')
		return (TRUE);
	else
		return (FALSE);
}
