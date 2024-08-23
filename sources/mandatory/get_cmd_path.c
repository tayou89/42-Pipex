/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:36:25 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 23:23:58 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd_split_array(char *cmd, t_data *data);
int		check_first_data_has_slash(char *first_string);
void	find_cmd_accessible_path(char *cmd, t_data *data);
void	execute_non_existent_cmd_process(t_data *data);

void	get_cmd_path(char *cmd, t_data *data)
{
	get_cmd_split_array(cmd, data);
	if (check_first_data_has_slash(data->cmd.split_array[0]) == TRUE)
	{
		data->cmd.path = ft_strdup(data->cmd.split_array[0]);
		if (data->cmd.path == (void *) 0)
			execute_error_process((void *) 0, 1, data);
	}
	else
		find_cmd_accessible_path(data->cmd.split_array[0], data);
	if (access(data->cmd.path, EXEC_OK) == -1)
		execute_error_process(data->cmd.path, 127, data);
}

void	get_cmd_split_array(char *cmd, t_data *data)
{
	if (*cmd == '\0')
	{
		data->cmd.split_array = (char **) malloc(sizeof(char *) * 2);
		if (data->cmd.split_array == (void *) 0)
			execute_error_process((void *) 0, 1, data);
		data->cmd.split_array[0] = ft_strdup("");
		if (data->cmd.split_array[0] == (void *) 0)
			execute_error_process((void *) 0, 1, data);
		data->cmd.split_array[1] = (void *) 0;
		return ;
	}
	data->cmd.split_array = ft_split(cmd, ' ');
	if (data->cmd.split_array == 0)
		execute_error_process((void *) 0, 1, data);
}

int	check_first_data_has_slash(char *first_string)
{
	char	*return_string;

	return_string = ft_strchr(first_string, '/');
	if (return_string == (void *) 0)
		return (FALSE);
	else
		return (TRUE);
}

void	find_cmd_accessible_path(char *cmd, t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd.directory[i] != (void *) 0)
	{
		data->cmd.path = ft_strjoin(data->cmd.directory[i], cmd);
		if (data->cmd.path == (void *) 0)
			execute_error_process((void *) 0, 1, data);
		if (access(data->cmd.path, F_OK) == 0
			&& access(data->cmd.path, X_OK) == 0)
			return ;
		free(data->cmd.path);
		data->cmd.path = (void *) 0;
		i++;
	}
	execute_non_existent_cmd_process(data);
}

void	execute_non_existent_cmd_process(t_data *data)
{
	ft_printf("%s: command not found\n", data->cmd.split_array[0]);
	free_every_mallocated_data(data);
	exit(127);
}
