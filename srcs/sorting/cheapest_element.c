/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:27:09 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 16:25:36 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_find_target(t_stack **stack_b, t_stack *counter_a)
{
	t_stack	*counter_b;
	t_stack	*target;
	int	tmp;

	tmp = INT32_MIN;
	counter_b = *stack_b;
	while (counter_b != NULL)
	{
		if ((counter_b->number < counter_a->number) && (counter_b->number > tmp))
		{
			tmp = counter_b->number;
			target = counter_b;
		}
		counter_b = counter_b->next;
	}
	if (tmp == INT32_MIN)
		target = ft_max_element(*stack_b);
	return (target);
}

/* This function loops through stack_a and calculates for every element the costs of rotating it to the top of the stack_a +
rotating stack_b to bring the target to the top of stack_b + pushing the element from stack_a to stack_b. The possibility of rotating
stack_a and stack_b at the same time has to be considered * 
*/
t_stack	*ft_cheapest_element(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*counter_a;
	t_stack *target_b;
	t_stack	*cheapest;
	int	insertion_steps;
	int	min_steps;

	min_steps = INT32_MAX;
	counter_a = *stack_a;

	while (counter_a != NULL)
	{
		target_b = ft_find_target(stack_b, counter_a);
		insertion_steps = ft_insertion_steps(stack_a, stack_b, counter_a, target_b);
		if (insertion_steps < min_steps)
		{
			min_steps = insertion_steps;
			cheapest = counter_a;
		}
		counter_a = counter_a->next;
	}
	return (cheapest);
}

int	ft_insertion_steps(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	int	steps;
	int tmp;

	steps = ft_steps_all_top(stack_a, stack_b, counter_a, target_b);
	tmp = ft_steps_all_bot(stack_a, stack_b, counter_a, target_b);
	if (tmp < steps)
		steps = tmp;
	tmp = ft_steps_top_bot(stack_a, stack_b, counter_a, target_b);
	if (tmp < steps)
		steps = tmp;
	tmp = ft_steps_bot_top(stack_a, stack_b, counter_a, target_b);
	if (tmp < steps)
		steps = tmp;
	return (steps);
}
