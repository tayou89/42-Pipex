/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:11:40 by tayou             #+#    #+#             */
/*   Updated: 2023/05/21 21:29:11 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_printf("Error.\n");
		ft_printf("Wrong argument count.\n");
		exit(0);
	}
}
