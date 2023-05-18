/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:47:46 by fran              #+#    #+#             */
/*   Updated: 2023/05/18 11:13:31 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int	content)
{
	t_stack	*newlist;

	newlist = malloc(sizeof(t_stack));
	if (!newlist)
		return (0);
	newlist->value = content;
	newlist->index = -1;
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
		printf("%i\n", stack->index);
		stack = stack->next;
	}
	if (!stack)
		printf("end\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**num_list;
	int		i;
	int		num_cont;

	i = 1;
	num_cont = argc;
	num_list = argv;
	stack_a = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		num_list = ft_split(argv[1], ' ');
		num_cont = split_word_counter(argv[1], ' ');
		i = 0;
	}
	while ( i < num_cont)
		add_stack_back(&stack_a, new_stack(ft_atoi(num_list[i++])));
	get_index(&stack_a);
	push_swap(&stack_a);
	return (0);
}
