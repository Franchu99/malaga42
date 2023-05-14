/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_utils,c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:11:34 by fran              #+#    #+#             */
/*   Updated: 2023/05/14 12:11:35 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	lstsize(t_stack *lst)
{
	int		c;

	c = 0;
	while (lst)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}

t_stack	*lstlast(t_stack *lst)
{
	int		size;

	size = lstsize(lst);
	while (size > 1)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}

t_stack	*get_n2lst(t_stack *lst)
{
	int		size;

	size = lstsize(lst);
	while (size > 2)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}