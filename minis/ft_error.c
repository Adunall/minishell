/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:48:03 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 01:46:37 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_error(char *str, int flag, t_data *data)
{
	if (flag == 1)
	{
		printf("%s", str);
		data->error_no = 1;
		exit(1);
	}
	else if (flag == 2)
	{
		printf("%s", str);
		data->error_no = 1;
	}
	else if (flag == 127)
	{
		printf("%s", str);
		data->error_no = 127;
	}
	else if (flag == 255)
	{
		printf("%s", str);
		data->error_no = 255;
		exit(255);
	}
	return ;
}
