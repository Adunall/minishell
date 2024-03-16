/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:13:44 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:13:48 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isalnum(44));
	printf("%d\n", ft_isalnum(88));
	printf("%d\n", ft_isalnum(111));
	printf("%d\n", ft_isalnum(144));
}
*/
