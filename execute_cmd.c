/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:23:21 by tayou             #+#    #+#             */
/*   Updated: 2023/05/11 00:53:39 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_2d_cmd_directory_array(t_data *data);
void	find_path_index_from_envp(int *path_index, char **envp);
void	get_2d_cmd_array(char *cmd, t_data *data);
void	execute_execve_function(t_data *data);

void	execute_cmd(char *cmd, t_data *data)
{
	get_2d_cmd_directory_array(data);
	get_2d_cmd_array(cmd, data);
	execute_execve_function(data);
	free_2d_array(data->array.cmd);
	free_2d_array(data->array.cmd_directory);
}

void	get_2d_cmd_directory_array(t_data *data)
{
	char	*directory_array;
	int		path_index;

	find_path_index_from_envp(&path_index, data->initial.envp);
	directory_array = (ft_strchr(data->initial.envp[path_index], '=') + 1);
	data->array.cmd_directory = ft_split(directory_array, ':');
	if (data->array.cmd_directory == (void *) 0)
	{
		ft_printf("Error.\nAllocating memory for cmd_directory is failed.\n");
		exit(1);
	}
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

void	get_2d_cmd_array(char *cmd, t_data *data)
{
	data->array.cmd = ft_split(cmd, ' ');
	if (data->array.cmd == (void *) 0)
	{
		free_2d_array(data->array.cmd_directory);
		ft_printf("Error.\nAllcating memory for cmd is failed.\n");
		exit(1);
	}
}

void	execute_execve_function(t_data *data)
{
	char	*initial_path;
	char	*final_path;
	int	i;

	i = 0;
	while (data->array.cmd_directory[i] != (void *) 0)
	{
		initial_path = ft_strjoin(data->array.cmd_directory[i], "/");
		final_path = ft_strjoin(initial_path, data->array.cmd[0]);
		free(initial_path);
		if (execve(final_path, data->array.cmd, data->initial.envp) != -1)
			break ;
		free(final_path);
		i++;
	}
	if (data->array.cmd_directory[i] == (void *) 0)
	{
		ft_printf("Error.\nExecuting cmd is failed.\n");
		free_2d_array(data->array.cmd);
		free_2d_array(data->array.cmd_directory);
		exit(2);
	}
}
