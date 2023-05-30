/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:28:07 by frangome          #+#    #+#             */
/*   Updated: 2023/05/29 21:08:43 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost;
	struct s_stack	*next;
}				t_stack;

int		strstrlen(char **strstr);
int		check_args(char *num);
int		check_equals(char **argv);
int		error_check(char **argv);

t_stack	*new_stack(int content);
void	add_stack_back(t_stack **lst, t_stack *new);
void	freelist(t_stack **stack);

void	swap_a(t_stack **stack);
void	push_a(t_stack **sa, t_stack **sb);
void	rotate_a(t_stack	**stack);
void	inv_rotate_a(t_stack **stack);

void	swap_b(t_stack **stack);
void	push_b(t_stack **sa, t_stack **sb);
void	rotate_b(t_stack **stack);
void	inv_rotate_b(t_stack **stack);

int		lstsize(t_stack *stack);
t_stack	*lstlast(t_stack *lst);
t_stack	*get_n2lst(t_stack *lst);

void	set_pos(t_stack	**stack);
int		get_mlindex(t_stack *stack_a, int index_num);
int		are_num_sort(t_stack *stack_a);
int		get_pos_of_max(t_stack *stack_a);
int		set_while(t_stack **stack_a, t_stack **tmpa, t_stack **tmpb);
void	set_target_pos(t_stack **stack_a, t_stack **stack_b);
void	calculate_cost(t_stack	*stack_a, t_stack **stack_b);

void	get_index(t_stack **stack);
t_stack	**sort_3_nodes(t_stack **stack);
t_stack	**push_swap(t_stack **stack);

void	do_stuff(t_stack **stack_a, t_stack **stack_b, t_stack *num_moved);
void	push_nums_back(t_stack **stack_a, t_stack **stack_b);
void	sort_num_in_a(t_stack	**stack_a, t_stack *stack_b);

int		get_min_cost(t_stack *stack_b);
void	sort_min_in_b(t_stack **stack_b, t_stack *tmp);
void	sort_a(t_stack **stack_a);
void	do_stuff_bigstack(t_stack **stack_a, t_stack *stack_b);
t_stack	**sort_big_stack(t_stack **stack_a);

#endif