/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:13:02 by fran              #+#    #+#             */
/*   Updated: 2023/04/25 21:36:10 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**node;

	node = malloc(ft_lstsize(lst) * sizeof(t_list));
	node = lst;
	while (lst)
	{
		(*node)->content = f(lst->content);
		(*node)->next = lst;
		lst = lst->next;
		if (lst)
			*node = lst;
	}
}
