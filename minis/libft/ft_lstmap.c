/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:15:16 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:15:20 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (0);
	first = 0;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&first, del);
			return (0);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

void	del(void *content)
{
	free(content);
}

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
/*
int	main(void)
{
	t_list	*lst;
	t_list	*lst1;

	lst = ft_lstnew(ft_strdup("yahya"));
	lst1 = ft_lstnew(ft_strdup("kocaeli"));
	lst->next = lst1;
	printf("%s\n", lst->content);
	printf("%s\n", lst1->content);
	ft_lstmap(lst, 'f', del);
}
*/
