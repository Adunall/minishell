/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:53:01 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 13:58:09 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	dollar_token(t_data *data)
{
	char *(str) = ft_strdup("");
	char *(nbr) = ft_itoa(data->error_no);
	if (data->purestr[data->i] == '?')
	{
		copy_to_str(data->lexer, nbr, data->lexer->fstr);
		data->i++;
	}
	else
	{
		if (!data->purestr[data->i])
			copy_to_str(data->lexer, "$", data->lexer->fstr);
		else
		{
			while (data->purestr[data->i] && (ft_isalnum(data->purestr[data->i])
					|| data->purestr[data->i] == 95))
			{
				str = ft_strjoin_char(str, data->purestr[data->i]);
				data->i++;
			}
			if (str)
				find_env_dollar(data, str);
		}
	}
	free(str);
	free(nbr);
}

void	lexer_token_quote_2(t_data *data)
{
	while (data->purestr[data->i])
	{
		if (data->purestr[data->i] == '"' && data->lexer->cift_tirnak)
			data->lexer->cift_tirnak = 0;
		else if (data->purestr[data->i] == '\'' && data->lexer->tek_tirnak)
			data->lexer->tek_tirnak = 0;
		else if (data->lexer->cift_tirnak && data->purestr[data->i] == '$')
		{
			data->i++;
			dollar_token(data);
			continue ;
		}
		if (!data->lexer->cift_tirnak && !data->lexer->tek_tirnak)
		{
			data->lexer->fstr = ft_strjoin_char(data->lexer->fstr,
					data->purestr[data->i]);
			data->i++;
			break ;
		}
		data->lexer->fstr = ft_strjoin_char(data->lexer->fstr,
				data->purestr[data->i]);
		data->i++;
	}
}

void	lexer_token_quote(t_data *data)
{
	data->lexer->tek_tirnak = 0;
	data->lexer->cift_tirnak = 0;
	if (data->purestr[data->i] == '"' && !data->lexer->tek_tirnak)
		data->lexer->cift_tirnak = 1;
	else if (data->purestr[data->i] == '\'' && !data->lexer->cift_tirnak)
		data->lexer->tek_tirnak = 1;
	data->lexer->fstr = ft_strjoin_char(data->lexer->fstr,
			data->purestr[data->i]);
	data->i++;
	lexer_token_quote_2(data);
}

int	lexer_two(t_data *data, t_lexer *lexer)
{
	char	str[2];

	if (data->purestr[data->i] == '"' || data->purestr[data->i] == '\'')
	{
		lexer_token_quote(data);
		return (0);
	}
	else if (data->purestr[data->i] == '$')
	{
		data->i++;
		dollar_token(data);
		return (0);
	}
	else if (!data->flag)
	{
		str[0] = data->purestr[data->i];
		str[1] = '\0';
		copy_to_str(lexer, str, lexer->fstr);
	}
	data->i++;
	data->flag = 0;
	return (1);
}

void	lexer(t_data *data)
{
	t_lexer *(lexer) = data->lexer;
	lexer->fstr = ft_strdup("");
	while (data->purestr[data->i])
	{
		if (data->purestr[data->i] == '|')
		{
			if (lexer_pipe(data, lexer) == 0)
				break ;
			data->flag = 1;
		}
		else if (data->purestr[data->i] == '<')
		{
			if (lexer_input(data, lexer) == 0)
				break ;
			data->flag = 1;
		}
		else if (data->purestr[data->i] == '>')
		{
			if (lexer_output(data, lexer) == 0)
				break ;
			data->flag = 1;
		}
		if (lexer_two(data, lexer) == 0)
			continue ;
	}
}
