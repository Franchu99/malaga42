/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:43:19 by fran              #+#    #+#             */
/*   Updated: 2023/05/17 18:14:15 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;
	int	index;
	int	flag;

	tmp = *stack;
	min = *stack;
	index = 0;
	flag = 0;
	
	while (index < lstsize(*stack))
	{	
		while (tmp)
		{
			if ((tmp->value < min->value || flag == 0) && tmp->index == -1)
			{
				min = tmp;	
				flag = 1;
			}
			tmp = tmp->next;
		}
		flag = 0;
		tmp = *stack;
		min->index = index++;
	}
}

t_stack	**sort_3_nodes(t_stack **stack)
{
	if ((*stack)->index == 0)
	{
		if (((*stack)->next)->index == 1)
			return (stack);
		else
			return (swap(stack), rotate(stack), stack);
	}
	else if ((*stack)->index == 1)
	{
		if (((*stack)->next)->index == 0)
			return (swap(stack), stack);
		else
			return (inv_rotate(stack), stack);
	}
	else
	{	
		if (((*stack)->next)->index == 0)
			return (rotate(stack), stack);
		else
			return (rotate(stack), swap(stack), stack);
	}	
}

t_stack	**push_swap(t_stack **stack)
{
	int	size;

	size = lstsize(*stack);
	if (size == 1)
		return (stack);
	else if (size == 2)
	{
		if ((*stack)->index == 0)
			return (stack);
		else
			return (swap(stack), stack);
	}
	else if (size == 3)
	 	return (sort_3_nodes(stack));
	return (0);
	// else
	// 	return (sort_big_stack(stack));
}
