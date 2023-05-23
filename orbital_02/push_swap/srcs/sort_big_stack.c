/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:24:13 by frangome          #+#    #+#             */
/*   Updated: 2023/05/23 16:47:21 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_nums_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpb;
	int		min_cost;;

	min_cost = 0;
	
	while (lstsize(*stack_b) > 0)
	{
		tmpb = *stack_b;
		min_cost = get_min_cost(*stack_b);
		while (tmpb != NULL)
		{
			if (tmpb->cost == min_cost)
			{
				sort_min_in_b(stack_b, tmpb);
				sort_num_in_a(stack_a, *stack_b);
				push_a(stack_b, stack_a);
				if (!*stack_b)
					break;
				if ((*stack_a)->target_pos == lstsize(*stack_a) - 1)
					rotate_a(stack_a);
				set_target_pos(stack_a, stack_b);
				calculate_cost(*stack_a, stack_b);
			}
			min_cost = get_min_cost(*stack_b);
			tmpb = tmpb->next;
		}
	}
}

void	sort_num_in_a(t_stack	**stack_a, t_stack *stack_b)
{
	int	size;
	int	count;

	size = lstsize(*stack_a);

	if (stack_b->target_pos <= size / 2)
	{
		count = stack_b->target_pos;
		while (count-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		count = size - stack_b->target_pos;
		while (count-- > 0)
			inv_rotate_a(stack_a);
	}
}

int	get_min_cost(t_stack *stack_b)
{
	int	min_cost;

	min_cost = stack_b->cost;
	while (stack_b)
	{
		if (stack_b->cost < min_cost)
			min_cost = stack_b->cost;
		stack_b = stack_b->next;
	}
	return (min_cost);
}

void	sort_min_in_b(t_stack **stack_b, t_stack *tmp)
{
	int	size_b;
	int	b_pos;

	size_b = lstsize(*stack_b);
	if (tmp->pos < size_b / 2)
	{
		b_pos = tmp->pos;
		while (b_pos-- > 0)
			rotate_b(stack_b);
	}
	else
	{
		b_pos = size_b - tmp->pos;
		while (b_pos-- > 0)
			inv_rotate_b(stack_b);
	}
	// while (b_pos > 0)
	// {
	// 	if (ref_pos >= size_b / 2)
	// 		inv_rotate_b(stack_b);
	// 	else
	// 		rotate_b(stack_b);
	// 	b_pos--;
	// }
}
void	sort_a(t_stack **stack_a)
{
	t_stack	*tmp;
	int		size;

	size = lstsize(*stack_a);
	tmp = *stack_a;
	while (tmp->index != 0)
		tmp = tmp->next;
	if (tmp->pos > size / 2)
	{
		while (tmp->pos != 0)
				inv_rotate_a(stack_a);
	}
	else
	{
		while (tmp->pos != 0)
			rotate_a(stack_a);
	}
}

t_stack	**sort_big_stack(t_stack **stack_a)
{
	t_stack *stack_b;

	stack_b = NULL;
	set_pos(stack_a);
	while(lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index > 2)
			push_b(stack_a, &stack_b);
		else
			rotate_a(stack_a);
	}
	stack_a = sort_3_nodes(stack_a);
	set_target_pos(stack_a, &stack_b);
	calculate_cost(*stack_a, &stack_b);
	push_nums_back(stack_a, &stack_b);
	sort_a(stack_a);
	return (0);
}
