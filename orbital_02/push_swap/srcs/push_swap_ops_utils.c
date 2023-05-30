/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:11:34 by fran              #+#    #+#             */
/*   Updated: 2023/05/30 16:33:22 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack	**stack)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}

int	get_mlindex(t_stack *stack_a, int index_num)
{
	int	min;

	min = 0;
	while (stack_a)
	{
		if (stack_a->index < index_num)
			min = stack_a->pos;
		stack_a = stack_a->next;
	}
	return (min);
}

int	lstsize(t_stack *stack)
{
	int	count;

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
