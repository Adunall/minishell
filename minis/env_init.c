/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:46:16 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/12/02 09:59:53 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

t_env	*node_add(t_env *new_node, int *count, int *len, char *str)
{
	if (new_node)
	{
		if (*count >= 1)
		{
			new_node->first = ft_substr(str, 0, *len);
			new_node->second = ft_strdup(ft_strchr(str, 61) + 1);
		}
		else
		{
			new_node->first = ft_strdup(str);
			new_node->second = ft_strdup("");
		}
	}
	return (new_node);
}

t_env	*create_env(char *str, t_data *data)
{
	int		len;
	int		count;
	t_env	*new_node;

	len = 0;
	count = 0;
	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		ft_error("Malloc Error", 1, data);
	while (str[len])
	{
		if (str[len] == '=')
		{
			count = 1;
			break ;
		}
		len++;
	}
	new_node = node_add(new_node, &count, &len, str);
	return (new_node);
}

void	add_env_node(char *str, t_data *data)
{
	t_env	*temp;
	t_env	*new_node;

	new_node = create_env(str, data);
	new_node->next = NULL;
	if (!new_node)
		ft_error("env_init/ malloc error", 1, data);
	if (data->env == NULL)
		data->env = new_node;
	else
	{
		temp = data->env;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	data->error_no = 0;
}

int	init_env(t_data *data)
{
	int	i;

	i = -1;
	while (data->envrt[++i] != NULL)
		add_env_node(data->envrt[i], data);
	return (1);
}
