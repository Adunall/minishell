/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:04:50 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 01:36:27 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	parse_three(char **command, t_data *data, char *new_cmd)
{
	if (ft_strcmp(new_cmd, "unset") == 0)
		unset(data, command);
	else if (ft_strcmp(new_cmd, "clear") == 0)
		printf("\033[H\033[J");
	else if (ft_strcmp(command[0], "exit") == 0)
		ft_exit(data, command);
	else if (((ft_strncmp(&command[0][0], "/", 1) == 0)
		|| ft_strncmp(&command[0][0], ".", 1) == 0))
		slash(command, data);
	else
		command_function(data, command);
}

void	parse_two(char **command, t_data *data)
{
	char *(new_cmd) = to_lowercase(command[0]);
	if (!new_cmd)
		ft_error("Malloc Error", 1, data);
	data->cmd_count = 0;
	while (command[data->cmd_count])
		data->cmd_count++;
	if (ft_strchr(command[0], '=') != NULL)
		ft_arguman_add(command, data);
	else if (ft_strcmp(new_cmd, "echo") == 0)
		ft_echo(command, 1, data);
	else if (ft_strcmp(new_cmd, "pwd") == 0)
		ft_pwd(data);
	else if (ft_strcmp(command[0], "cd") == 0)
		ft_cd(command, data);
	else if (ft_strcmp(new_cmd, "env") == 0)
		env_print(data, 0);
	else if (ft_strcmp(command[0], "export") == 0)
		export(data, command);
	else
		parse_three(command, data, new_cmd);
	free(new_cmd);
}

void	parse(char **command, t_data *data)
{
	if (!command || !command[0])
	{
		ft_error("", 127, data);
		return ;
	}
	else
		parse_two(command, data);
	return ;
}
