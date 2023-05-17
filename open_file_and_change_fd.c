/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_and_change_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:18:09 by tayou             #+#    #+#             */
/*   Updated: 2023/05/17 14:27:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file_1_and_get_fd(t_data *data);
void	change_file_1_fd_to_standard_input(t_data *data);

void	open_file_and_change_fd(char *file_path, int fd_to_change)
{
	int	fd;
	int	new_fd;

	fd = open(file_path, RDONLY);
	if (fd == -1)
		execute_error_process(OPEN_ERROR, data);
	new_fd = dup2(fd, fd_to_change);
	if (new_fd == -1)
		execute_error_process(DUP_ERROR, data);
}
