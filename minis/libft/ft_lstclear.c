/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:14:49 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:14:52 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}
/*
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;

	lst = ft_lstnew(ft_strdup("yahya"));
	lst1 = ft_lstnew(ft_strdup("yasar"));
	lst2 = ft_lstnew(ft_strdup("42"));
	lst->next = lst1;
	lst1->next = lst2;
	printf("%s\n", lst->content);
	printf("%s\n", lst1->content);
	printf("%s\n", lst2->content);
	ft_lstclear(&lst, del);
	printf("%s\n", lst->content);
	printf("%s\n", lst1->content);
	printf("%s\n", lst2->content);
}
*/
