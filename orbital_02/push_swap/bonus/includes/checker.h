/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:24:08 by frangome          #+#    #+#             */
/*   Updated: 2023/05/31 18:06:33 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

int		strstrlen(char **strstr);
int		check_args(char *num);
int		check_equals(char **argv);
int		error_check(char **argv);

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

void	read_file(t_stack **stack_a);

int		make_operation(char *operation, t_stack **stack_a, t_stack **stack_b);
int		check_inv_rotate(char *operation, t_stack **stack_a, t_stack **stack_b);
int		check_push(char *operation, t_stack **stack_a, t_stack **stack_b);
int		check_swap(char *operation, t_stack **stack_a, t_stack **stack_b);

#endif