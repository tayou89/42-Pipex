/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc_exist_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:22:17 by tayou             #+#    #+#             */
/*   Updated: 2023/06/04 22:15:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_heredoc_exist(char **argv, t_data *data)
{
	char	*string_to_check;
	int		string_length;
	int		strncmp_return;

	string_to_check = "here_doc";
	string_length = ft_strlen(string_to_check);
	strncmp_return = ft_strncmp(argv[1], string_to_check, string_length);
	if (strncmp_return == 0)
		data->flag.heredoc_exist = TRUE;
	else
		data->flag.heredoc_exist = FALSE;
}
