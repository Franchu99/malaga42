/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:16:44 by frangome          #+#    #+#             */
/*   Updated: 2023/05/29 18:46:06 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		set_pos(stack);
		ft_printf("sa\n");
	}
}

void	push_a(t_stack **sa, t_stack **sb)
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
	ft_printf("pa\n");
}

void	rotate_a(t_stack	**stack)
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
	ft_printf("ra\n");
}

void	inv_rotate_a(t_stack **stack)
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
	ft_printf("rra\n");
}
