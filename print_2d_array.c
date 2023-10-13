/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2d_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:49:28 by tayou             #+#    #+#             */
/*   Updated: 2023/05/24 13:50:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_2d_array(char **array)
{
	int	i;

	if (array == (void *) 0)
		return ;
	i = 0;
	while (array[i] != (void *) 0)
	{
		ft_printf("array[%d]: %s\n", i, array[i]);
		i++;
	}
}

