#include "push_swap.h"
#include <stdio.h>

int	main()
{
	t_stack	*sa1;
	t_stack	*sa2;
	t_stack	*sa3;

	sa1 = malloc(sizeof(t_stack));
	sa2 = malloc(sizeof(t_stack));
	sa3 = malloc(sizeof(t_stack));

	sa1->value = 1;
	sa1->next = sa2;

	sa2->value = 2;
	sa2->next = sa3;

	sa3->value = 3;
	sa3->next = NULL;



	printf("%i\n%i\n%i\n\n", sa1->value, (sa1->next)->value, ((sa1->next)->next)->value);
	rotate(&sa1);
	printf("%i\n%i\n%i\n", sa1->value, (sa1->next)->value, ((sa1->next)->next)->value);
}