/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:15:22 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/28 19:28:20 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //entfernen!

void	ft_print_stack(t_stack *stck)
{
	while (stck)
	{
		printf("number: %i	", stck->number);
		printf("index: %i\n", stck->index);
		
		stck = stck->next;
	}
}

int main(int argc, char **argv)
{
	// handle different command line argument inputs and make an array of number strings of it.
	char	**array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
		array = &argv[1];
	else
		return (ft_error());
	
		
	// transform the array of number strings to a stack build as a doubly linked list.
	// check for multiple occurence of numbers. If multiple occurence, then free the stack and print error message (ft_error in ft_free_stack)
	if (ft_make_stack_a(array, &stack_a) == 1)
	{
		if (argc == 2)
			ft_free_array(array);
		return (ft_error());
	}

	// test stack_a before sorting algorithm
	// printf("stack_a:\n");
	// ft_print_stack(stack_a);
	// printf("stack_b:\n");
	// ft_print_stack(stack_b);
	
	global_variable = 0;
	
	// sorting algorithm
	ft_sorting_algorithm(&stack_a, &stack_b);


	// printf("stack_a:\n");
	// ft_print_stack(stack_a);
	// printf("stack_b:\n");
	// ft_print_stack(stack_b);
	
	// printf("Anzahl Operationen: %d", global_variable);



	// free the array that was allocated by ft_split.
	if (argc == 2)
		ft_free_array(array);
	
	// at the end of the program, the stacks need to be freed
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
