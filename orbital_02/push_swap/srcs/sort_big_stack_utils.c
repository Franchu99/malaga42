/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:41:48 by frangome          #+#    #+#             */
/*   Updated: 2023/05/30 16:32:30 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
