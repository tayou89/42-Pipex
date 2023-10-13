/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_error_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:03:32 by tayou             #+#    #+#             */
/*   Updated: 2023/05/31 23:48:47 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_error_process(int error_number, int exit_number, t_data *data)
{
	free_every_mallocated_data(data);
	print_error_message(error_number);
	exit(exit_number);
}

void	print_error_message(int error_number)
{
	if (error_number == MALLOC_ERROR)
		ft_printf("Memory allocating failed.\n");
	else if (error_number == DUP_ERROR)
		ft_printf("Function dup failed.\n");
	else if (error_number == CMD_ERROR)
		ft_printf("CMD not found or Permission denied.\n");
	else if (error_number == FORK_ERROR)
		ft_printf("Function fork failed.\n");
	else if (error_number == OPEN_ERROR)
		ft_printf("File not found or Permission denied.\n");
	else if (error_number == PIPE_ERROR)
		ft_printf("Function pipe failed.\n");
	else if (error_number == STOP_ERROR)
		ft_printf("Invalid stop string for heredoc.\n");
}
