/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:24:18 by aweissha          #+#    #+#             */
/*   Updated: 2023/12/01 13:55:22 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_first_two(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_b) < 2 && ft_stsize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
}

void	ft_insert_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_a) > 3)
	{
		rotate(stack_a, stack_b, ft_cheapest_element(stack_a, stack_b));
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

void	ft_push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	counter;

	ft_rotate_max_up(stack_b);
	counter = 0;
	if ((((*stack_b)->number) > ((*stack_a)->number))
		&& (((*stack_b)->number) < ((*stack_a)->next->number)))
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
	if (ft_stsize(*stack_a) >= 3)
	{
		ft_first_two(stack_a, stack_b);
		ft_insert_algorithm(stack_a, stack_b);
		ft_sort_three(stack_a);
		if (*stack_b != NULL)
			ft_push_back(stack_a, stack_b);
	}
	else if (ft_stsize(*stack_a) == 2)
		ft_sort_two(stack_a);
}
