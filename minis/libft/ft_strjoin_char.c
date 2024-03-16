/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:17:34 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/28 00:06:40 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *s, char c)
{
	char	*new_str;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	if (s)
		len = ft_strlen(s);
	new_str = (char *)malloc(len + 2);
	if (!new_str)
		return (NULL);
	if (s)
		ft_strlcpy(new_str, s, len + 1);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	free(s);
	return (new_str);
}
