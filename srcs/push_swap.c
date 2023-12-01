/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:15:22 by aweissha          #+#    #+#             */
/*   Updated: 2023/12/01 15:35:16 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_print_stack(t_stack *stck)
// {
// 	while (stck)
// 	{
// 		printf("number: %i	", stck->number);
// 		printf("index: %i\n", stck->index);
// 		stck = stck->next;
// 	}
// }

int	main(int argc, char **argv)
{
	char	**array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
		array = &argv[1];
	else
		return (ft_error());
	if (ft_make_stack_a(array, &stack_a) == 1)
	{
		if (argc == 2)
			ft_free_array(array);
		return (ft_error());
	}
	ft_sorting_algorithm(&stack_a, &stack_b);
	if (argc == 2)
		ft_free_array(array);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
