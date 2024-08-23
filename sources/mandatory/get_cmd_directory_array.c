/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_directory_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:28:09 by tayou             #+#    #+#             */
/*   Updated: 2023/06/03 22:03:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path_index_from_envp(int *path_index, char **envp);
void	split_directory_array(char *directory_array, t_data *data);
void	join_slash_to_each_directory(t_data *data);

void	get_cmd_directory_array(t_data *data)
{
	char	*directory_array;
	int		path_index;

	find_path_index_from_envp(&path_index, data->args.envp);
	directory_array = (ft_strchr(data->args.envp[path_index], '=') + 1);
	split_directory_array(directory_array, data);
	join_slash_to_each_directory(data);
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
			break ;
	}
	*path_index = i;
}

void	split_directory_array(char *directory_array, t_data *data)
{
	data->cmd.directory = ft_split(directory_array, ':');
	if (data->cmd.directory == (void *) 0)
		execute_error_process((void *) 0, 1, data);
}

void	join_slash_to_each_directory(t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	while (data->cmd.directory[i] != (void *) 0)
	{
		temp = data->cmd.directory[i];
		data->cmd.directory[i] = ft_strjoin(temp, "/");
		if (data->cmd.directory[i] == (void *) 0)
		{
			free(temp);
			execute_error_process((void *) 0, 1, data);
		}
		free(temp);
		i++;
	}
}
