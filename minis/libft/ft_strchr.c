/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:17:00 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:17:04 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(s);
	while (i >= j)
	{
		if (s[j] == (char)c)
		{
			return ((char *)s + j);
		}
		j++;
	}
	return (NULL);
}
/*
int main()
{
	char a[] = "yahyaysr";
   	printf("%s", ft_strchr(a, 'h'));
}
	//stringin içinde aradığı charı bulduktan sonra hepsini yazdırır
*/
