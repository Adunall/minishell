/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:07:56 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 01:25:27 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int	delete_env(t_data *data, char *delete_env, int i)
{
	t_env	*current;
	t_env	*prev;

	current = data->env;
	prev = NULL;
	while (delete_env[++i])
		if (delete_env[i] == '=')
			break ;
	while (current != NULL)
	{
		if (ft_strncmp(current->first, delete_env, i) == 0)
		{
			if (prev == NULL)
				data->env = current->next;
			else
				prev->next = current->next;
			free(current->first);
			free(current->second);
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

int	delete_arg(t_data *data, char *delete_arg, int i)
{
	t_arguman	*current;
	t_arguman	*prev;

	current = data->arguman;
	prev = NULL;
	while (delete_arg[++i])
		if (delete_arg[i] == '=')
			break ;
	while (current != NULL)
	{
		if (ft_strncmp(current->first, delete_arg, i) == 0)
		{
			if (prev == NULL)
				data->arguman = current->next;
			else
				prev->next = current->next;
			free(current->first);
			free(current->second);
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

void	unset(t_data *data, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		delete_env(data, cmd[i], -1);
		delete_arg(data, cmd[i], -1);
	}
	data->error_no = 0;
}
