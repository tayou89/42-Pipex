/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:31:07 by tayou             #+#    #+#             */
/*   Updated: 2023/05/11 00:32:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define RDONLY		0
# define STDIN		0

# define TRUE		1
# define FALSE		0

typedef struct s_initial
{
	char	*file_1;
	char	*cmd_1;
	char	*cmd_2;
	char	*file_2;
	char	**envp;
}	t_initial;

typedef struct s_fd
{
	int	file_1;
	int	new_file_1;
}	t_fd;

typedef struct s_array
{
	char	**cmd;
	char	**cmd_directory;
}	t_array;

typedef struct s_data
{
	t_initial	initial;
	t_fd		fd;
	t_array		array;
}	t_data;

void	check_argc(int argc);
void	get_initial_data(char **argc, char **envp, t_data *data);
void	make_file_1_to_standard_input(t_data *data);
void	execute_cmd(char *cmd, t_data *data);

void	free_2d_array(char **array);

void	print_2d_array(char **array);

#endif
