/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:06:51 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/28 19:00:02 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *tmp;
	
	if (*stack_2 != NULL)
	{
		tmp = *stack_1;
		*stack_1 = *stack_2;
		*stack_2 = (*stack_2)->next;
		if (*stack_2 != NULL)
			(*stack_2)->previous = NULL;
		(*stack_1)->next = tmp;
		if (tmp != NULL)
			tmp->previous = *stack_1;
		ft_set_index(*stack_1);
		ft_set_index(*stack_2);		
	}
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
			// global_variable++; // entfernen
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
			// global_variable++; // entfernen
}
