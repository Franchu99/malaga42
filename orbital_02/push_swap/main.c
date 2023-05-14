/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:47:46 by fran              #+#    #+#             */
/*   Updated: 2023/05/14 22:02:45 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	c;
	int	num;
	int	sign;

	sign = 1;
	c = 0;
	num = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\t'
		|| str[c] == '\r' || str[c] == '\v' || str[c] == '\f')
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while ((str[c] >= '0' && str[c] <= '9'))
	{
		num = num * 10 + (str[c] - '0');
		c++;
	}
	return (sign * num);
}

t_stack	*new_stack(int	content)
{
	t_stack	*newlist;

	newlist = malloc(sizeof(t_stack));
	if (!newlist)
		return (0);
	newlist->value = content;
	newlist->next = NULL;
	return (newlist);
}

void	add_stack_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = lstlast(*lst);
		last->next = new;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%i\n", stack->value);
		stack = stack->next;
	}
	printf("end\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while ( i < argc)
	{
		add_stack_back(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	print_stack(stack_a);
	return (0);
}
