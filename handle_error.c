/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:42:01 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 22:11:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_message(int	error_number);

void	execute_error_process(int error_number, t_data *data)
{
	print_error_message(error_number);
	free_every_mallocated_data(data);
	exit(1);
}

void	print_error_message(int	error_number)
{
	if (error_number == MALLOC_ERROR)
		ft_printf("Error.\nMemory allocating failed.\n");
	else if (error_number == EXECVE_ERROR)
		ft_printf("Error.\nFunction execve failed.\n");
	else if (error_number == CMD_ERROR)
		ft_printf("Error.\nCMD not found or Permission denied.\n");
	else if (error_number == FORK_ERROR)
		ft_printf("Error.\nFunction fork failed.\n");
	else if (error_number == OPEN_ERROR)
		ft_printf("Error.\nFile not found or Permission denied.\n");
	else if (error_number == READ_ERROR)
		ft_printf("Error.\nReading file failed.\n");
	else if (error_number == PIPE_ERROR)
		ft_printf("Error.\nFunction pipe failed.\n");
}
