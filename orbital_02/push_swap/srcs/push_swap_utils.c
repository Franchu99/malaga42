/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:47:01 by frangome          #+#    #+#             */
/*   Updated: 2023/05/30 16:33:41 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_num_sort(t_stack *stack_a)
{
	while (stack_a->next)
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
	while (stack_a)
	{
		if (stack_a->index > max->index)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max->pos);
}

int	set_while(t_stack **stack_a, t_stack **tmpa, t_stack **tmpb)
{
	t_stack	*last;
	int		flag;

	last = lstlast(*stack_a);
	flag = 0;
	*tmpa = *stack_a;
	while (*tmpa)
	{
		if ((*tmpb)->index < (*tmpa)->index && flag == 0)
		{
			if ((*tmpb)->index < last->index)
				(*tmpb)->target_pos = get_mlindex(*stack_a, (*tmpb)->index) + 1;
			else
				(*tmpb)->target_pos = (*tmpa)->pos;
			flag = 1;
		}
		*tmpa = (*tmpa)->next;
	}
	return (flag);
}

void	set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpb;
	t_stack	*tmpa;
	int		flag;

	tmpb = *stack_b;
	while (tmpb)
	{
		flag = set_while(stack_a, &tmpa, &tmpb);
		if (flag == 0)
		{
			if (!are_num_sort(*stack_a))
				tmpb->target_pos = get_pos_of_max(*stack_a) + 1;
			else
				tmpb->target_pos = 0;
		}
		tmpb = tmpb->next;
	}
}

void	calculate_cost(t_stack	*stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		size_b;
	int		size_a;
	int		tar_p;
	int		p;

	size_b = lstsize(*stack_b);
	size_a = lstsize(stack_a);
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->target_pos > size_a / 2)
			tar_p = size_a - (tmp->target_pos + 1);
		else
			tar_p = tmp->target_pos;
		if (tmp->pos > size_b / 2)
		{
			p = size_b - (tmp->pos);
		}
		else
			p = tmp->pos;
		tmp->cost = tar_p + p + 1;
		tmp = tmp->next;
	}
}
