/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_and_write_to_heredoc_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:19:51 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 23:37:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		check_line_same_with_stop_string(char *line, t_data *data);
void	check_stop_string_validation(t_data *data);

void	read_line_and_write_to_heredoc(t_data *data)
{
	char	*line;

	check_stop_string_validation(data);
	while (data->flag.same_with_stop_string == FAIL)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (line == (void *) 0)
		{
			ft_printf("Fail to read line.\n");
			continue ;
		}
		if (check_line_same_with_stop_string(line, data) == TRUE)
			data->flag.same_with_stop_string = TRUE;
		else
			write(data->fd.heredoc, line, ft_strlen(line));
		free_1d_array(line);
	}
	close_fd(data->fd.heredoc);
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

void	check_stop_string_validation(t_data *data)
{
	if (data->stop_string[0] == '\0')
		execute_error_process(STOP_ERROR, 1, data);
}
