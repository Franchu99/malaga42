/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:39:00 by frangome          #+#    #+#             */
/*   Updated: 2023/08/30 17:31:54 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack	*new_stack(int content)
{
	t_stack	*newlist;

	newlist = malloc(sizeof(t_stack));
	if (!newlist)
		return (0);
	newlist->value = content;
	newlist->index = -1;
	newlist->pos = -1;
	newlist->target_pos = -1;
	newlist->cost = -1;
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

void	error_output(int argc, char **num_list)
{
	if (argc == 2)
		freechrchr(num_list);
	ft_printf("Error\n");
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
	if (error_check(num_list))
		return (error_output(argc, num_list), 0);
	while (i < num_cont)
		add_stack_back(&stack_a, new_stack(ft_atoi(num_list[i++])));
	if (argc == 2)
		freechrchr(num_list);
	return (get_index(&stack_a), push_swap(&stack_a), free_stack(&stack_a), 0);
}
