/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:18:22 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:18:25 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *set, size_t n)
{
	size_t	len;

	len = ft_strlen(set);
	if (!*set)
		return ((char *)s1);
	while (*s1 && n-- >= len)
	{
		if (*s1 == *set && !ft_memcmp(s1, set, len))
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	a[] = "yahya42cursus";
	char	b[] =  "42";

	printf("%s\n", ft_strnstr(a, b, 10));
}
*/
