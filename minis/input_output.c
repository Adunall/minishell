/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:51:30 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 01:41:08 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*add_character_to_index(char *str, char c, int i)
{
	char	*s;
	int		y;
	int		z;
	int		x;

	x = -1;
	z = -1;
	y = ft_strlen(str);
	s = malloc(sizeof(char) * y + 1);
	while (++x <= y)
	{
		if (x == i)
		{
			s[x] = c;
		}
		else
			s[x] = str[++z];
	}
	free(str);
	s[x] = '\0';
	return (s);
}

void	redirection_to_input(char **cmd, int fd, int i)
{
	while (cmd[++i])
	{
		if (!ft_strncmp(cmd[i], "<<", 3))
		{
			if (fd > 0)
				close(fd);
			fd = operation(cmd[i + 1]);
		}
	}
	i = -1;
	while (fd > -1 && cmd[++i])
		if (!ft_strncmp(cmd[i], "<", 2))
			fd = open(cmd[i + 1], O_RDONLY);
	if (fd > 0)
	{
		dup2(fd, 0);
		close(fd);
	}
	else if (fd < 0)
	{
		printf("minishell: %s: no such file or directory\n", cmd[i + 1]);
		return (exit(1));
	}
}

void	output_two(char **cmd, int i, int fd, int x)
{
	if (!x++)
	{
		fd = open(cmd[i + 1], O_CREAT | O_APPEND | O_WRONLY, 0000644);
		dup2(fd, 1);
	}
	else
		fd = open(cmd[i + 1], O_CREAT, 0000644);
	close(fd);
}

void	redirection_to_output(char **cmd, int i, int fd, int x)
{
	while (cmd[i])
		i++;
	if (i < 2)
		return ;
	while (--i > -1)
	{
		if (!ft_strncmp(cmd[i], ">", 2))
		{
			if (!x++)
			{
				fd = open(cmd[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0000644);
				dup2(fd, 1);
			}
			else
				fd = open(cmd[i + 1], O_CREAT | O_TRUNC, 0000644);
			close(fd);
		}
		else if (!ft_strncmp(cmd[i], ">>", 3))
			output_two(cmd, i, fd, x);
	}
}

char	*re_create_input(char *input)
{
	int	i;

	i = -1;
	while (input[++i] != '\0')
	{
		if (input[i] == '<' || input[i] == '>')
		{
			input = add_character_to_index(input, ' ', i + 1 + (input[i
						+ 1] == input[i]));
			input = add_character_to_index(input, ' ', i);
			i += 1 + (input[i + 2] == input[i + 1]);
		}
	}
	return (input);
}
