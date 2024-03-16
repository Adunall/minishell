/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:15:10 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:15:14 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;

	lst = ft_lstnew("yahya");
	lst1 = ft_lstnew("42");
	lst2 = ft_lstnew("kou");
	lst->next = lst1;
	lst1->next = lst2;
	printf("%s", ft_lstlast(lst)->content);
}
*/
