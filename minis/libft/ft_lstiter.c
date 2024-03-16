/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:15:03 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:15:07 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != 0)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	f(void *content)
{
	int		i;
	char	*str;

	str = (char *)content;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*lst2;

	lst = ft_lstnew(ft_strdup("HeLLo"));
	lst2 = ft_lstnew(ft_strdup("SeLaMDuNYa"));
	lst->next = lst2;
	printf("%s\n", lst->content);
	printf("%s\n", lst2->content);
	ft_lstiter(lst, f);
	printf("%s\n", lst->content);
	printf("%s\n", lst2->content);
}
*/
