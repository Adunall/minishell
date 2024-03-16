/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:52:17 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 12:38:28 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <string.h>

void	copy_to_str(t_lexer *lexer, char *str, char *fstr)
{
	size_t	str_len;
	size_t	fstr_len;
	char	*new_fstr;

	str_len = ft_strlen(str);
	fstr_len = ft_strlen(fstr);
	new_fstr = (char *)malloc(str_len + fstr_len + 1);
	if (new_fstr)
	{
		ft_strcpy(new_fstr, fstr);
		ft_strcat(new_fstr, str);
		free(fstr);
		lexer->fstr = new_fstr;
	}
}

char	*single_quote(t_data *data, char *str, int *i)
{
	data->lexer->tek_tirnak = 0;
	data->lexer->cift_tirnak = 0;
	char *(new_str) = strdup(str);
	free(str);
	if (data->lexer->fstr[*i] == '"' && !data->lexer->tek_tirnak)
		data->lexer->cift_tirnak = 1;
	else if (data->lexer->fstr[*i] == '\'' && !data->lexer->cift_tirnak)
		data->lexer->tek_tirnak = 1;
	new_str = ft_strjoin_char(new_str, data->lexer->fstr[(*i)++]);
	while (data->lexer->fstr[*i])
	{
		if (data->lexer->fstr[*i] == '"' && data->lexer->cift_tirnak)
			data->lexer->cift_tirnak = 0;
		else if (data->lexer->fstr[*i] == '\'' && data->lexer->tek_tirnak)
			data->lexer->tek_tirnak = 0;
		if (!data->lexer->cift_tirnak && !data->lexer->tek_tirnak)
		{
			new_str = ft_strjoin_char(new_str, data->lexer->fstr[*i]);
			(*i)++;
			return (new_str);
		}
		new_str = ft_strjoin_char(new_str, data->lexer->fstr[*i]);
		(*i)++;
	}
	return (0);
}

void	space_sg2(t_data **data, int *i, int *flag, char **str)
{
	if ((*data)->lexer->fstr[*i] == ' ' || (*data)->lexer->fstr[*i] == '\t')
	{
		if (!(*flag))
		{
			*str = ft_strjoin_char(*str, ' ');
			*flag = 1;
		}
		(*i)++;
		while ((*data)->lexer->fstr[*i] == ' '
			|| (*data)->lexer->fstr[*i] == '\t')
			(*i)++;
	}
	else
	{
		*flag = 0;
		*str = ft_strjoin_char(*str, (*data)->lexer->fstr[*i]);
		(*i)++;
	}
}

char	*space_single(t_data *data)
{
	int (i) = 0;
	int (flag) = 0;
	char *(str) = ft_strdup("");
	while (data->lexer->fstr[i] == ' ' || data->lexer->fstr[i] == '\t')
		i++;
	while (data->lexer->fstr[i])
	{
		if (data->lexer->fstr[i] == '"' || data->lexer->fstr[i] == '\'')
		{
			str = single_quote(data, str, &i);
			if ((data)->lexer->fstr[i] == ' '
				|| (data)->lexer->fstr[i] == '\t')
			{
				str = ft_strjoin_char(str, ' ');
				flag = 1;
			}
		}
		else
			space_sg2(&data, &i, &flag, &str);
	}
	return ((data->adem = strdup(str)), str);
}
