/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:47:01 by frangome          #+#    #+#             */
/*   Updated: 2023/05/22 22:02:03 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack	**stack)
{
	t_stack	*tmp;
	int	pos;

	pos = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}

int	get_max_low_index(t_stack *stack_a, int index_num)
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

int	are_num_sort(t_stack *stack_a)
{
	while(stack_a->next)
	{
		if ((stack_a->next)->index < stack_a->index)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	get_pos_of_max(t_stack *stack_a)
{
	t_stack	*max;

	max = stack_a;
	while(stack_a)
	{
		if (stack_a->index > max->index)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max->pos);
}

void set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmpb;
	t_stack *tmpa;
	t_stack *last;
	int flag;

	last = lstlast(*stack_a);
	tmpb = *stack_b;
	while (tmpb)
	{
		flag = 0;
		tmpa = *stack_a;
		while (tmpa)
		{
			if (tmpb->index < tmpa->index && flag == 0)
			{
				if (tmpb->index < last->index)
				{
					tmpb->target_pos = get_max_low_index(*stack_a, tmpb->index) + 1;
				}
				else
				{
					tmpb->target_pos = tmpa->pos;
				}
				flag = 1;
			}
			tmpa = tmpa->next;
		}
		if (flag == 0)
		{
			if(!are_num_sort(*stack_a))
			{
				tmpb->target_pos = get_pos_of_max(*stack_a) + 1;
			}
			else
			{
				tmpb->target_pos = last->pos + 1;
			}
		}
		tmpb = tmpb->next;
	}
}

void	calculate_cost(t_stack	*stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int	size_b;
	int	size_a;
	int	tar_p;
	int	p;

	size_b = lstsize(*stack_b);
	size_a = lstsize(stack_a);
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->target_pos >= size_a / 2)
			tar_p = size_a - tmp->target_pos + 1;
		else
			tar_p = tmp->target_pos;
		if (tmp->pos >= size_b / 2)
			p = size_b - tmp->pos;
		else
			p = tmp->pos;
		tmp->cost = tar_p + p + 1;
		tmp = tmp->next;
	}
}
