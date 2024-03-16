/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:16:00 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:16:04 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!src && !dest)
		return (0);
	if (dest < src)
		ft_memcpy(dest, src, len);
	if (dest > src)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	d[] = "kocaeli";
	printf("%s", ft_memmove(d + 4, d + 2, 5));
	return (0);
}
*/
