/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:43:19 by fran              #+#    #+#             */
/*   Updated: 2023/07/05 21:30:18 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;
	int		index;
	int		flag;

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
	if (lstsize(*stack) > 3)
		return (0);
	if ((*stack)->index == 0)
	{
		if (((*stack)->next)->index == 1)
			return (stack);
		else
			return (swap_a(stack), rotate_a(stack), stack);
	}
	else if ((*stack)->index == 1)
	{
		if (((*stack)->next)->index == 0)
			return (swap_a(stack), stack);
		else
			return (inv_rotate_a(stack), stack);
	}
	else
	{	
		if (((*stack)->next)->index == 0)
			return (rotate_a(stack), stack);
		else
			return (rotate_a(stack), swap_a(stack), stack);
	}	
}

int	is_sorted(t_stack *stack)
{
	int	boolean;

	boolean = 1;
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			boolean = 0;
		stack = stack->next;
	}
	return (boolean);
}

void	push_swap(t_stack **stack)
{
	int	size;

	size = lstsize(*stack);
	if (is_sorted(*stack))
		return ;
	if (size == 2)
	{
		if ((*stack)->index != 0)
			swap_a(stack);
	}
	else if (size == 3)
		sort_3_nodes(stack);
	else
		sort_big_stack(stack);
}
