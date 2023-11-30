/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:35:54 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 16:25:23 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_steps_all_top(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	if ((counter_a->index) >= (target_b->index))
		return (counter_a->index);
	else
		return (target_b->index);
}

int	ft_steps_all_bot(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	if ((ft_stsize(*stack_a) - (counter_a->index)) >= (ft_stsize(*stack_b) - (target_b->index)))
		return (ft_stsize(*stack_a) - (counter_a->index));
	else
		return (ft_stsize(*stack_b) - (target_b->index));
}

int	ft_steps_top_bot(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	return ((counter_a->index) + (ft_stsize(*stack_b) - (target_b->index)));
}

int	ft_steps_bot_top(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	return ((target_b->index) + (ft_stsize(*stack_a) - (counter_a->index)));
}
