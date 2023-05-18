/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:24:13 by frangome          #+#    #+#             */
/*   Updated: 2023/05/18 22:50:16 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_nums_back(t_list **stack_a, t_list **stack_b)
{
	t_stack	*tmpb;
	int		size_b;
	int		min_cost;

	tmpb = *stack_b;
	min_cost = 0;
	tmpb = *stack_b;
	size_b = lstsize(*stack_b);
	while (size_b > 0)
	{
		min_cost = get_min_cost(*stack_b);
		while (tmpb)
		{
			if (tmpb->cost == min_cost)
			{
				sort_min_in_b(stack_a, stack_b, tmpb);
				sort_num_in_a(stack_a, stack_b);
			}
			tmpb = tmpb->next;
		}
	}
}

void	sort_num_in_a(t_stack	**stack_a, t_stack *stack_b)
{
	int	possition;


	possition = (*stack_a)->target_pos;
	
	while (possition > 0)
	{
		
		possition--;
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

void	sort_min_in_b(t_stack **stack_a, t_stack **stack_b, t_stack *tmp)
{
	int	size_b;

	size_b = lstsize(*stack_b);
	while (tmp->pos != 0)
	{
		if (tmp->pos >= size_b / 2)
			inv_rotate(stack_b);
		else
			rotate(stack_b);
	}
	// push(stack_b, stack_a);
	// set_target_pos(stack_a, &stack_b);
	// calculate_cost(*stack_a, &stack_b);
}

t_stack	**sort_big_stack(t_stack **stack_a)
{
	t_stack *stack_b;

	stack_b = NULL;
	set_pos(stack_a);
	while(lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index > 2)
		{
			while ((*stack_a)->pos > 0)
			{
				rotate(stack_a);
			}
			push(stack_a, &stack_b);
		}
		rotate(stack_a);
	}
	stack_a = sort_3_nodes(stack_a);
	print_stack(*stack_a);
	set_target_pos(stack_a, &stack_b);
	calculate_cost(*stack_a, &stack_b);
	print_stack(stack_b);
	
	return (0);
}
