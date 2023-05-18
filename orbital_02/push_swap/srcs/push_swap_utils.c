/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:47:01 by frangome          #+#    #+#             */
/*   Updated: 2023/05/18 20:44:47 by frangome         ###   ########.fr       */
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

void	set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpa;
	t_stack *tmpb;
	int		flag;

	tmpb = *stack_b;
	while (tmpb)
	{
		tmpa = *stack_a;
		flag = 0;
		while (tmpa)
		{
			if (tmpb->index < tmpa->index && flag == 0)
			{
				tmpb->target_pos = tmpa->pos;
				flag = 1;
			}
			tmpa = tmpa->next;
		}
		if(flag ==0)
			tmpb->target_pos = lstsize(*stack_a);
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