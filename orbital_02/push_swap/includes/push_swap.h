/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:28:07 by frangome          #+#    #+#             */
/*   Updated: 2023/05/17 18:11:19 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_stack
{
	int				value;
	int				index;
	// int				pos;
	// int				target_pos;
	// int				cost_a;
	// int				cost_b;
	struct s_stack	*next;
}				t_stack;

void	swap(t_stack **stack);
void	push(t_stack **sa, t_stack **sb);
void	rotate(t_stack	**stack);
t_stack	*lstlast(t_stack *lst);
int		lstsize(t_stack *lst);
t_stack	*get_n2lst(t_stack *lst);
void	inv_rotate(t_stack **stack);
void	get_index(t_stack **stack);
t_stack	**push_swap(t_stack **stack);

#endif