/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:39:20 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 16:26:48 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_move_all_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0 && target_b->index != 0)
		ft_rr(stack_a, stack_b);
	while (cheapest_element->index != 0)
		ft_ra(stack_a);
	while (target_b->index != 0)
		ft_rb(stack_b);
}

void	ft_move_all_bot(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0 && target_b->index != 0)
		ft_rrr(stack_a, stack_b);
	while (cheapest_element->index != 0)
		ft_rra(stack_a);
	while (target_b->index != 0)
		ft_rrb(stack_b);
}

void	ft_move_top_bot(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0)
		ft_ra(stack_a);
	while (target_b->index != 0)
		ft_rrb(stack_b);
}

void	ft_move_bot_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0)
		ft_rra(stack_a);
	while (target_b->index != 0)
		ft_rb(stack_b);
}

/* This function rotates stack_a until the cheapest element is at the top. Stack_b gets rotated until the target is at the top.
 If possible, the two stacks rotate at the same time using rr or rrr.
*/
void	ft_execute_rotations(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element)
{
	t_stack	*target_b;
	int		a;
	int		b;
	int		c;
	int		d;
	
	target_b = ft_find_target(stack_b, cheapest_element);
	a = ft_steps_all_top(stack_a, stack_b, cheapest_element, target_b);
	b = ft_steps_all_bot(stack_a, stack_b, cheapest_element, target_b);
	c = ft_steps_top_bot(stack_a, stack_b, cheapest_element, target_b);
	d = ft_steps_bot_top(stack_a, stack_b, cheapest_element, target_b);
	
	if (a <= b && a <= c && a <= d)
		ft_move_all_top(stack_a, stack_b, cheapest_element, target_b);
	else if (b <= a && b <= c && b <= d)
		ft_move_all_bot(stack_a, stack_b, cheapest_element, target_b);
	else if (c <= a && c <= b && c <= d)
		ft_move_top_bot(stack_a, stack_b, cheapest_element, target_b);
	else
		ft_move_bot_top(stack_a, stack_b, cheapest_element, target_b);
}
