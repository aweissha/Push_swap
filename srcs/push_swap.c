/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:15:22 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/24 16:49:19 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //entfernen!
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
	
	// check the array of strings for correctness of the input
	// if (ft_check_input(array) == 1)
	// 	return (ft_error());
		
	// transform the array of number strings to a stack build as a doubly linked list.
	// check for multiple occurence of numbers. If multiple occurence, then free the stack and print error message (ft_error in ft_free_stack)
	if (ft_make_stack_a(array, &stack_a) == 1)
	{
		if (argc == 2)
			ft_free_array(array);
		return (ft_error());
	}
	
	// if (ft_check_multiples(stack_a) == 1)
	// {
	// 	ft_free_stack(stack_a);
	// 	ft_free_array(array);
	// 	return (ft_error());
	// }


	
	// free the array that was allocated by ft_split.
	if (argc == 2)
		ft_free_array(array);
	
	// sorting algorithm



	// testing...otate
	t_stack *test;

	test = stack_a;
	printf("stack_a:\n");
	while (test)
	{
		printf("number: %i	", test->number);
		printf("index: %i\n", test->index);
		
		
		test = test->next;
	}
	
	ft_sorting_algorithm(&stack_a, &stack_b);
	
	printf("stack_a:\n");
	while (stack_a)
	{
		printf("number: %i	", stack_a->number);
		printf("index: %i\n", stack_a->index);
		
		
		stack_a = stack_a->next;
	}
	printf("stack_b:\n");	
	while (stack_b)
	{
		printf("number: %i	", stack_b->number);
		printf("index: %i\n", stack_b->index);
		
		stack_b = stack_b->next;
	}



	
	// at the end of the program, the stacks need to be freed
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
