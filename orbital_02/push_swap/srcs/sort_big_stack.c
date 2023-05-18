/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:24:13 by frangome          #+#    #+#             */
/*   Updated: 2023/05/18 11:11:57 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**sort_big_stack(t_stack **stack_a)
{
    t_stack *stack_b;
    int     size;

    size = lstsize(*stack_a);
    while(size > 3)
    {
        push(stack_a, &stack_b);
        size--;
    }
    print_stack(*stack_a);
    stack_a = sort_3_nodes(stack_a);
    print_stack(*stack_a);
    return (0);
}