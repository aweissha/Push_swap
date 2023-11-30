/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:24:18 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 16:28:26 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Pushes tho two upper elements of stack_a to stack_b.
void	ft_first_two(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_b) < 2 && ft_stsize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
}

void	ft_insert_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_a) > 3)
	{
		ft_execute_rotations(stack_a, stack_b, ft_cheapest_element(stack_a, stack_b));
		ft_pb(stack_a, stack_b);
	}
}

void	ft_sort_three(t_stack **stck)
{
	int	max_index;
	
	max_index = ft_max_index(*stck);
	if (max_index == 0)
		ft_ra(stck);
	else if (max_index == 1)
		ft_rra(stck);
	if (ft_check_ascending(*stck) == 1)
		ft_sa(stck);
}

/*This function Pushes back all the descendingly sorted elements of stack_b to stack_a.
The three ascendingly sorted elements of stack_a have to be considered*/
void	ft_push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	counter;
	
	ft_rotate_max_up(stack_b);
	counter = 0;
	if ((((*stack_b)->number) > ((*stack_a)->number)) && (((*stack_b)->number) < ((*stack_a)->next->number)))
	{
		ft_ra(stack_a);
		counter = 2;
	}
	else if ((((*stack_b)->number) < ((*stack_a)->number)))
		counter = 3;
	while (*stack_b != NULL)
	{
		if ((ft_stlast(*stack_a)->number) > ((*stack_b)->number) && counter < 3)
		{
			ft_rra(stack_a);
			counter++;
		}
		else
			ft_pa(stack_a, stack_b);
	}
	while (ft_check_ascending(*stack_a) != 0)
		ft_rra(stack_a);
}

void	ft_sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	// Push the first two elements of stack_a to stack_b
	ft_first_two(stack_a, stack_b);

	/* calculate the costs for each element of stack_a to bring to the top and insert into the correct position of stack_b.
	Then executing the insertion for the cheapest element.**/
	ft_insert_algorithm(stack_a, stack_b);

	// /*Sort the remaining three elements of stack_a*/
	ft_sort_three(stack_a);

	// /*Push all the now descending sorted elements of stack_b back to stack_a. The remaining three elements of stack_a have to be considered.*/
	if (*stack_b != NULL)
		ft_push_back(stack_a, stack_b);
}
