/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:24:13 by frangome          #+#    #+#             */
/*   Updated: 2023/05/22 22:03:00 by frangome         ###   ########.fr       */
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
				push(stack_b, stack_a);
				//printf("b->a ");
				if (!*stack_b)
					break;
				if ((*stack_a)->target_pos == lstsize(*stack_a) - 1)
				{
					rotate(stack_a);
					//printf("_a ");
				}
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
		while (count > 0)
		{
			rotate(stack_a);
			//printf("_a ");
			count--;
		}
	}
	else
	{
		count = size - stack_b->target_pos;
		while (count > 0)
		{
			inv_rotate(stack_a);
			//printf("_a ");
			count--;
		}
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
	b_pos = tmp->pos;
	while (b_pos > 0)
	{
		if (tmp->pos >= size_b / 2)
		{
			inv_rotate(stack_b);
			//printf("_b ");
		}
		else
		{
			rotate(stack_b);
			//printf("_b ");
		}
		b_pos--;
	}
}
void	sort_a(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->index != 0)
	{
		rotate(stack_a);
		//printf("_a ");
		tmp = *stack_a;	
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
		{
			push(stack_a, &stack_b);
			//printf("_a ");
		}
		else
		{
			rotate(stack_a);
			//printf("_a ");
		}
	}
	stack_a = sort_3_nodes(stack_a);
	set_target_pos(stack_a, &stack_b);
	calculate_cost(*stack_a, &stack_b);
	push_nums_back(stack_a, &stack_b);
	sort_a(stack_a);
	return (0);
}
