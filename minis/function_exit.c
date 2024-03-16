/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:50:07 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/12/09 14:08:41 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_exit(t_data *data, char **command)
{
	data->error_no = 0;
	int (len) = 0;
	int (i) = 0;
	while (command[len])
		len++;
	if (len == 1)
		exit (0);
	else if (len == 2 && (command[1][i] >= '0' && command[1][i] <= '9'))
		exit (0);
	else if (len > 2 && (command[1][i] >= '0' && command[1][i] <= '9'))
	{
		printf("exit\nbash: %s: ", command[0]);
		ft_error("too many arguments\n", 2, data);
	}
	else if (len >= 2 && !(command[1][i] >= '0' && command[1][i] <= '9'))
	{
		printf("exit\nbash: %s: %s: ", command[0], command[1]);
		ft_error("numeric argument required\n", 255, data);
	}
	return ;
}
