/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:15:22 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/21 18:10:35 by aweissha         ###   ########.fr       */
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
	stack_a = ft_make_stack_a(array);
	stack_b = NULL;
	
	// check for multiple occurence of numbers. If multiple occurence, then free the stack and print error message (ft_error in ft_free_stack)
	if (ft_check_multiples(stack_a) == 1)
	{
		ft_free_stack(stack_a);
		return (ft_error());
	}

	// free the array that was allocated by ft_split.
	if (argc == 2)
		ft_free_array(array);



	// testing...
	while (stack_a)
	{
		printf("%li\n", stack_a->number);
		stack_a = stack_a->next;
	}
	
	// at the end of the program, the stacks need to be freed
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}