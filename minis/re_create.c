/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:34:45 by adunal            #+#    #+#             */
/*   Updated: 2023/11/28 03:15:30 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

char	**re_create_cmd(char **ex_cmd, int len, int i, int j)
{
	char	**cmd;

	while (ex_cmd[++i])
	{
		if (!ft_strncmp(ex_cmd[i], "<", 2) || !ft_strncmp(ex_cmd[i], ">", 2)
			|| !ft_strncmp(ex_cmd[i], "<<", 3) || !ft_strncmp(ex_cmd[i], ">>",
				3))
			i++;
		else
			len++;
	}
	cmd = malloc(sizeof(char *) * (len + 1));
	i = -1;
	j = 0;
	while (ex_cmd[++i])
	{
		if (!ft_strncmp(ex_cmd[i], "<", 2) || !ft_strncmp(ex_cmd[i], ">", 2)
			|| !ft_strncmp(ex_cmd[i], "<<", 3) || !ft_strncmp(ex_cmd[i], ">>",
				3))
			i++;
		else
			cmd[j++] = ft_strdup(ex_cmd[i]);
	}
	cmd[j] = NULL;
	return (cmd);
}
