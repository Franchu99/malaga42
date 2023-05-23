/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:28:07 by frangome          #+#    #+#             */
/*   Updated: 2023/05/23 14:49:12 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost;
	struct s_stack	*next;
}				t_stack;

void 	swap_a(t_stack **stack);
void 	swap_b(t_stack **stack);
void	push_a(t_stack **sa, t_stack **sb);
void	push_b(t_stack **sa, t_stack **sb);
void	rotate_a(t_stack	**stack);
void	rotate_b(t_stack	**stack);
void	inv_rotate_a(t_stack **stack);
void	inv_rotate_b(t_stack **stack);
t_stack	*lstlast(t_stack *lst);
int		lstsize(t_stack *lst);
t_stack	*get_n2lst(t_stack *lst);
void	get_index(t_stack **stack);
t_stack	**push_swap(t_stack **stack);
t_stack	**sort_3_nodes(t_stack **stack);
void	print_stack(t_stack *stack);
t_stack	**sort_big_stack(t_stack **stack_a);
void	set_pos(t_stack	**stack);
void	set_target_pos(t_stack **stack_a, t_stack **stack_b);
void	calculate_cost(t_stack	*stack_a, t_stack **stack_b);
void	sort_num_in_a(t_stack	**stack_a, t_stack *stack_b);
void	sort_min_in_b(t_stack **stack_b, t_stack *tmp);
int		get_min_cost(t_stack *stack_b);
int		get_pos_of_max(t_stack *stack_a);

#endif