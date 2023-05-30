/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:24:13 by frangome          #+#    #+#             */
/*   Updated: 2023/05/30 16:32:18 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_stuff(t_stack **stack_a, t_stack **stack_b, t_stack *num_moved)
{
	sort_min_in_b(stack_b, num_moved);
	sort_num_in_a(stack_a, *stack_b);
	push_a(stack_b, stack_a);
	set_target_pos(stack_a, stack_b);
	calculate_cost(*stack_a, stack_b);
}

void	push_nums_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpb;
	t_stack	*num_moved;
	int		min_cost;

	min_cost = 0;
	while (lstsize(*stack_b) > 0)
	{
		tmpb = *stack_b;
		min_cost = get_min_cost(*stack_b);
		while (tmpb != NULL)
		{
			if (tmpb->cost == min_cost)
			{
				num_moved = tmpb;
				do_stuff(stack_a, stack_b, num_moved);
				min_cost = get_min_cost(*stack_b);
				break ;
			}
			tmpb = tmpb->next;
		}
		if (!*stack_b)
			break ;
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

void	do_stuff_bigstack(t_stack **stack_a, t_stack *stack_b)
{
	set_target_pos(stack_a, &stack_b);
	calculate_cost(*stack_a, &stack_b);
	push_nums_back(stack_a, &stack_b);
	sort_a(stack_a);
}

t_stack	**sort_big_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	size = lstsize(*stack_a);
	stack_b = NULL;
	set_pos(stack_a);
	while (lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index > 2)
		{
			if ((*stack_a)->index < (size / 2))
				push_b(stack_a, &stack_b);
			else
			{
				push_b(stack_a, &stack_b);
				rotate_b(&stack_b);
			}
		}
		else
			rotate_a(stack_a);
	}
	stack_a = sort_3_nodes(stack_a);
	do_stuff_bigstack(stack_a, stack_b);
	return (0);
}
