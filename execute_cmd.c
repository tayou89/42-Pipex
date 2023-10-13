/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:23:21 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 21:53:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd_directory_and_split_array(char *cmd, t_data *data);
void	find_path_index_from_envp(int *path_index, char **envp);
void	find_cmd_path(t_data *data);
void	free_unnecessary_data(t_data *data);

void	execute_cmd(char *cmd, t_data *data)
{
	int	execve_return;

	get_cmd_directory_and_split_array(cmd, data);
	find_cmd_path(data);
	execve_return = \
		execve(data->cmd.path, data->cmd.split_array, data->args.envp);
	if (execve_return == -1)
		execute_error_process(EXECVE_ERROR, data);
	free_unnecessary_data(data);
}

void	get_cmd_directory_and_split_array(char *cmd, t_data *data)
{
	char	*directory_array;
	int		path_index;

	find_path_index_from_envp(&path_index, data->args.envp);
	directory_array = (ft_strchr(data->args.envp[path_index], '=') + 1);
	data->cmd.directory = ft_split(directory_array, ':');
	if (data->cmd.directory == (void *) 0)
		execute_error_process(MALLOC_ERROR, data);
	data->cmd.split_array = ft_split(cmd, ' ');
	if (data->cmd.split_array == (void *) 0)
		execute_error_process(MALLOC_ERROR, data);
}

void	find_path_index_from_envp(int *path_index, char **envp)
{
	char	*haystack;
	char	*needle;
	int		len;
	int		i;

	needle = "PATH=";
	len = ft_strlen(needle);
	i = 0;
	while (envp[i] != (void *) 0)
	{
		haystack = envp[i];
		if (ft_strnstr(haystack, needle, len) == (void *) 0)
			i++;
		else
			break;
	}
	*path_index = i;
}

void	find_cmd_path(t_data *data)
{
	char	*initial_path;
	int	i;

	i = 0;
	while (data->cmd.directory[i] != (void *) 0)
	{
		initial_path = ft_strjoin(data->cmd.directory[i], "/");
		if (initial_path == (void *) 0)
			execute_error_process(MALLOC_ERROR, data);
		data->cmd.path = ft_strjoin(initial_path, data->cmd.split_array[0]);
		if (data->cmd.path == (void *) 0)
			execute_error_process(MALLOC_ERROR, data);
		free(initial_path);
		initial_path = (void *) 0;
		if (access(data->cmd.path, F_OK) == 0
			&& access(data->cmd.path, X_OK) == 0)
			break ;
		free(data->cmd.path);
		data->cmd.path = (void *) 0;
		i++;
	}
	if (data->cmd.directory[i] == (void *) 0)
		execute_error_process(CMD_ERROR, data);
}

void	free_unnecessary_data(t_data *data)
{
	free(data->cmd.path);
	data->cmd.path = (void *) 0;
	free_2d_array(data->cmd.split_array);
}
