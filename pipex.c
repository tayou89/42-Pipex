/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:32:18 by tayou             #+#    #+#             */
/*   Updated: 2023/05/10 15:26:03 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data *data;

	if (argc != 5)
		return (0);
	get_file_1_fd(argv[1], &data);
}

void	get_file_1_fd(char *file_path, t_data *data)
{
	data->file_1_fd = open(file_path, O_RDONLY);
	if (data->file_1_fd < 0)
		return (
