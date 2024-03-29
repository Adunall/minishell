/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:52:34 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 02:26:12 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	find_env_two(t_env *tmp, char *str, t_data *data, int *flag)
{
	while (tmp)
	{
		if (ft_strcmp(tmp->first, str) == 0)
		{
			data->a = 1;
			*flag = 1;
			data->flag_dollar = 1;
			if (data->a == 1)
				copy_to_str(data->lexer, tmp->second, data->lexer->fstr);
			break ;
		}
		tmp = tmp->next;
	}
}

void	find_env_dollar(t_data *data, char *str)
{
	t_env *(tmp) = data->env;
	t_arguman *(arg_tmp) = data->arguman;
	t_lexer *(lexer) = data->lexer;
	int (flag) = 0;
	data->a = 0;
	find_env_two(tmp, str, data, &flag);
	while (arg_tmp && !flag)
	{
		if (ft_strcmp(arg_tmp->first, str) == 0)
		{
			data->a = 2;
			data->flag_dollar = 1;
			break ;
		}
		arg_tmp = arg_tmp->next;
	}
	if (data->a == 2)
		copy_to_str(lexer, arg_tmp->second, lexer->fstr);
	else
		copy_to_str(lexer, "", lexer->fstr);
}

int	lexer_input(t_data *data, t_lexer *lexer)
{
	if (data->purestr[data->i + 1] == '<')
	{
		copy_to_str(lexer, " << ", lexer->fstr);
		data->i++;
	}
	else
		copy_to_str(lexer, " < ", lexer->fstr);
	data->token++;
	return (1);
}

int	lexer_output(t_data *data, t_lexer *lexer)
{
	if (data->purestr[data->i + 1] == '>')
	{
		copy_to_str(lexer, " >> ", lexer->fstr);
		data->i++;
	}
	else
		copy_to_str(lexer, " > ", lexer->fstr);
	data->token++;
	return (1);
}

int	lexer_pipe(t_data *data, t_lexer *lexer)
{
	data->pipe_count++;
	copy_to_str(lexer, " | ", lexer->fstr);
	return (1);
}
