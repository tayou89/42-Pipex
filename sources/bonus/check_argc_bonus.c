/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:02:18 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:33:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_argc(int argc, t_data *data)
{
	if (data->flag.heredoc_exist == TRUE)
	{
		if (argc < 6)
		{
			ft_printf("Error.\n");
			ft_printf("Wrong argument count.\n");
			exit(0);
		}
	}
	else
	{
		if (argc < 5)
		{
			ft_printf("Error.\n");
			ft_printf("Wrong argument count.\n");
			exit(0);
		}
	}
}
