/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:49:29 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/12/09 14:04:02 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <string.h>

void	print_echo_quote(t_data *data, char *str, int *i)
{
	data->lexer->tek_tirnak = 0;
	data->lexer->cift_tirnak = 0;
	if (str[*i] == '"' && !data->lexer->tek_tirnak)
		data->lexer->cift_tirnak = 1;
	else if (str[*i] == '\'' && !data->lexer->cift_tirnak)
		data->lexer->tek_tirnak = 1;
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '"' && data->lexer->cift_tirnak)
			data->lexer->cift_tirnak = 0;
		else if (str[*i] == '\'' && data->lexer->tek_tirnak)
			data->lexer->tek_tirnak = 0;
		if (!data->lexer->cift_tirnak && !data->lexer->tek_tirnak)
		{
			(*i)++;
			break ;
		}
		else
		{
			write(1, &str[*i], 1);
			(*i)++;
		}
	}
}

int	ft_echo_two(char **cmd, t_data *data, int *flag, int *i)
{
	data->error_no = 0;
	if (!cmd[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		(*i)++;
		*flag = 0;
	}
	return (1);
}

int	ft_echo(char **cmd, int i, t_data *data)
{
	int (flag) = 1;
	char *(str);
	if (ft_echo_two(cmd, data, &flag, &i) == 0)
		return (0);
	int (j) = 0;
	if (cmd[i] && cmd[i][0])
	{
		str = strstr(data->adem, cmd[i]);
		while (str[j])
		{
			if (str[j] == '\'' || str[j] == '"')
			{
				print_echo_quote(data, str, &j);
				continue ;
			}
			else if (str[j] == '|' || str[j] == '>' || str[j] == '<')
				break ;
			else
				write(1, &str[j], 1);
			j++;
		}
	}
	if (flag)
		printf("\n");
	return (0);
}
