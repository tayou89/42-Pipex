/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:42:01 by tayou             #+#    #+#             */
/*   Updated: 2023/05/17 14:44:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_error_process(int error_number, t_data *data)
{
	print_error_message(error_number, data);
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
		ft_printf("Error.\nFile open failed.\n");
}
