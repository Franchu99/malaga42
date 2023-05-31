/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:04:28 by frangome          #+#    #+#             */
/*   Updated: 2023/05/31 18:08:07 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_swap(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (operation[1] == 'a')
	{
		swap_a(stack_a);
		return (1);
	}
	else if (operation[1] == 'b')
	{
		swap_b(stack_b);
		return (1);
	}
	else if (operation[1] == 's')
	{
		swap_a(stack_a);
		swap_b(stack_b);
		return (1);
	}
	else
		return (0);
}

int	check_push(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (operation[1] == 'a')
	{
		push_a(stack_b, stack_a);
		return (1);
	}
	else if (operation[1] == 'b')
	{
		push_b(stack_a, stack_b);
		return (1);
	}
	else
		return (0);
}

int	check_inv_rotate(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (operation[2] == '\n')
	{
		rotate_a(stack_a);
		rotate_b(stack_b);
		return (1);
	}
	else if (operation[2] == 'a')
	{
		inv_rotate_a(stack_a);
		return (1);
	}
	else if (operation[2] == 'b')
	{
		inv_rotate_b(stack_b);
		return (1);
	}
	else if (operation[2] == 'r')
	{
		inv_rotate_a(stack_a);
		inv_rotate_b(stack_b);
		return (1);
	}
	else
		return (0);
}

int	make_operation(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (operation[0] == 's')
		return (check_swap(operation, stack_a, stack_b));
	else if (operation[0] == 'p')
		return (check_push(operation, stack_a, stack_b));
	else if (operation[0] == 'r')
	{
		if (operation[1] == 'a')
		{
			rotate_a(stack_a);
			return (1);
		}
		else if (operation[1] == 'b')
		{
			rotate_b(stack_b);
			return (1);
		}
		else if (operation[1] == 'r')
		{
			check_inv_rotate(operation, stack_a, stack_b);
			return (1);
		}
		return (0);
	}
	else
		return (0);
}
