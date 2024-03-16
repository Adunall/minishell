/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:15:40 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:15:43 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
			return (a + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	a[] = "malatya";
	printf("%s", ft_memchr(a, 't', 6));
}
*/
