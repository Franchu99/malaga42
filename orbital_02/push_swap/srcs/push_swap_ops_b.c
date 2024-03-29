/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:44:51 by frangome          #+#    #+#             */
/*   Updated: 2023/05/29 18:46:16 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		set_pos(stack);
		ft_printf("sb\n");
	}
}

void	push_b(t_stack **sa, t_stack **sb)
{
	t_stack	*tmp;

	if (*sa == NULL && *sb == NULL)
		return ;
	tmp = (*sa)->next;
	(*sa)->next = *sb;
	*sb = *sa;
	*sa = tmp;
	set_pos(sa);
	set_pos(sb);
	ft_printf("pb\n");
}

void	rotate_b(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	last = lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
	set_pos(stack);
	ft_printf("rb\n");
}

void	inv_rotate_b(t_stack **stack)
{
	t_stack	*n2lst;
	t_stack	*lst;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	n2lst = get_n2lst(*stack);
	lst = n2lst->next;
	lst->next = *stack;
	n2lst->next = NULL;
	*stack = lst;
	set_pos(stack);
	ft_printf("rrb\n");
}
