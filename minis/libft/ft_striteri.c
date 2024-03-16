/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:17:28 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:17:31 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	ft_upper(unsigned int i, char *s)
{
	int	c;

	c = 0;
	i = 0;
	if (*s)
	{
		s[c] = s[c] - 32;
	}
}

int	main ()
{
	char p[] = "YAhya";
	ft_striteri(p, ft_upper);
	printf("%s",p);
}
*/
