/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:16:14 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:16:18 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <fcntl.h>

int	main(void)
{
	int	fd = open("dosya.txt", O_WRONLY | O_CREAT | O_RDONLY, 777);
	int	fd2 = open("yahya.txt", O_WRONLY | O_CREAT | O_RDONLY, 777);

	ft_putchar_fd('c', fd);
	ft_putchar_fd('z', fd2);
	printf("%d\n", fd);
	printf("%d", fd2);
}*/
