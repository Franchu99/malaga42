/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:11:34 by fran              #+#    #+#             */
/*   Updated: 2023/05/19 15:49:51 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int lstsize(t_stack *stack)
{
	int count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
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
