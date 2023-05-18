/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:16:44 by frangome          #+#    #+#             */
/*   Updated: 2023/05/18 20:40:22 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	set_pos(stack);
	printf("swap ");
}

void	push(t_stack **sa, t_stack **sb)
{
	t_stack	*tmp;

	tmp = (*sa)->next;
	(*sa)->next = *sb;
	*sb = *sa;
	*sa = tmp;
	set_pos(sa);
	set_pos(sb);
	printf("push ");
}

void	rotate(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = (*stack)->next;
	last = lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
	set_pos(stack);
	printf("rotate ");
}

void	inv_rotate(t_stack **stack)
{
	t_stack	*n2lst;
	t_stack	*lst;

	n2lst = get_n2lst(*stack);
	lst = n2lst->next;
	lst->next = *stack;
	n2lst->next = NULL;
	*stack = lst;
	set_pos(stack);
	printf("inv_rotate ");
}