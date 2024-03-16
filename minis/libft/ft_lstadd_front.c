/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:14:42 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/11/25 15:14:46 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*new;

	new = ft_lstnew("42");
	ft_lstadd_front(&lst, new);
	printf("%s\n", lst->content);
	printf("%s\n", new->content);
	printf("%p", new->next);
}
*/
