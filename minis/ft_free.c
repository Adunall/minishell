/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:48:19 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 02:26:12 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

char	**ft_free_malloc(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_data(t_data *data, char *command)
{
	if (data->lexer->fstr && !data->pipe_count)
		free(data->lexer->fstr);
	if (data->lexer && !data->pipe_count)
		free(data->lexer);
	if (data->purestr)
		free(data->purestr);
	if (data->adem)
		free(data->adem);
	if (data->arg && !data->pipe_count && !data->flag_token)
		ft_free_malloc(data->arg);
	(void)command;
	if (command)
		free(command);
}
