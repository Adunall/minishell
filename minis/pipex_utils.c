/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:06:26 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 02:36:42 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	g_signal_no = 0;

void	ft_sig_heredoc(int sig_nbr)
{
	if (sig_nbr == 2)
	{
		g_signal_no = 1;
	}
}

int	operation(char *x)
{
	char	*input;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (perror("Pipe is not created!\n"), exit(1), 1);
	input = readline("> ");
	while (input != NULL && ft_strncmp(input, x, ft_strlen(x) + 1))
	{
		signal(SIGINT, ft_sig_heredoc);
		if (g_signal_no)
			break ;
		write(pipefd[1], input, ft_strlen(input));
		write(pipefd[1], "\n", 1);
		free(input);
		input = readline("> ");
	}
	close(pipefd[1]);
	free(input);
	return (pipefd[0]);
}

void	execute_first_command(t_data *data, char **cmd, int *fd)
{
	data->has_pipe = 1;
	*fd = comment(data, cmd, 0, 1);
}

void	execute_commands(t_data *data, char **cmd, int *fd)
{
	data->has_pipe = 0;
	comment(data, cmd, *fd, 1);
}

char	*create_path(char *cmd, char **cmd_paths)
{
	char	*tmp;
	char	*tmp_cmd;
	char	**tmp_cmd_paths;

	tmp_cmd_paths = cmd_paths;
	while (cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		tmp_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(tmp_cmd, F_OK))
			return (ft_free_str(tmp_cmd_paths), tmp_cmd);
		free(tmp_cmd);
		cmd_paths++;
	}
	return (NULL);
}
