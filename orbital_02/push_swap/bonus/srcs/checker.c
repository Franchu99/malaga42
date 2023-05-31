/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:11:28 by frangome          #+#    #+#             */
/*   Updated: 2023/05/31 20:16:21 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <fcntl.h>

int	is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->next->value < stack_a->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	read_file(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		fd;
	char	*line;
	int		size;

	stack_b = NULL;
	size = lstsize(*stack_a);
	fd = open("operations", O_RDONLY);
	if (fd == -1)
		return ;
	while ((line = get_next_line(fd)) != NULL)
	{
		make_operation(line, stack_a, &stack_b);
		free(line);
	}
	if (lstsize(*stack_a) != size)
	{
		ft_printf("KO");
		return ;
	}
	if (is_sorted(*stack_a))
		ft_printf("OK");
	else
		ft_printf("KO");
	return ;
}
