/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:53:23 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/12/09 14:09:28 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

void	init_lexer(t_data *data, char *command)
{
	data->purestr = ft_strdup(command);
	data->pipe_count = 0;
	data->token = 0;
	data->i = 0;
	data->flag = 0;
	lexer(data);
	lexer_error_control(data);
	if (data->flag_token)
		data->pipe_count = 0;
}

char	*minishell_two(t_data *data)
{
	char	*command;

	data->quotes_flag = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig);
	command = readline("\033[31madembusrashell >>\033[0m ");
	if (command == NULL)
		ft_sig(4);
	add_history(command);
	int (nbr) = quotes_control(command);
	if (!nbr)
	{
		ft_error("syntax error: quotes not closed `'' or `\"'\n", 127, data);
		data->quotes_flag = 1;
		data->flag_token = 1;
		free(command);
		return (command);
	}
	data->lexer = (t_lexer *)malloc(sizeof(t_lexer));
	init_lexer(data, command);
	return (command);
}

void	minishell_three(t_data *data)
{
	if (data->token)
	{
		data->has_pipe = 0;
		comment(data, data->arg, 0, 1);
		data->token = 0;
	}
	else
		parse(data->arg, data);
}

void	minishell(t_data *data)
{
	char	*command;

	while (1)
	{
		command = minishell_two(data);
		if (!data->flag_token)
		{
			if (data->pipe_count > 0)
				pipex(data, -1, 0);
			else
			{
				data->arg = ft_split(data->lexer->fstr, ' ');
				if (!data->arg)
					break ;
				minishell_three(data);
			}
		}
		if (!data->quotes_flag)
			free_data(data, command);
		if (data->flag_token)
			data->flag_token = 0;
	}
}

int	main(int argc, char **argv, char **envarment)
{
	t_data	data;

	(void)argc;
	(void)argv;
	set_args(&data);
	data.envrt = envarment;
	init_env(&data);
	minishell(&data);
	return (1);
}
