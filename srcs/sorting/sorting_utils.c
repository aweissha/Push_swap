/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:32:30 by aweissha          #+#    #+#             */
/*   Updated: 2023/12/01 12:34:07 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_max_number(t_stack *stck)
{
	int	max_number;

	max_number = stck->number;
	while (stck != NULL)
	{
		if (stck->number > max_number)
			max_number = stck->number;
		stck = stck->next;
	}
	return (max_number);
}

int	ft_max_index(t_stack *stck)
{
	int	max_number;
	int	max_index;

	max_number = stck->number;
	max_index = 0;
	while (stck != NULL)
	{
		if (stck->number > max_number)
		{
			max_index = stck->index;
			max_number = stck->number;
		}
		stck = stck->next;
	}
	return (max_index);
}

t_stack	*ft_max_element(t_stack *stck)
{
	int		max_number;
	t_stack	*max;

	max_number = stck->number;
	max = stck;
	while (stck != NULL)
	{
		if (stck->number > max_number)
		{
			max = stck;
			max_number = stck->number;
		}
		stck = stck->next;
	}
	return (max);
}

int	ft_check_ascending(t_stack *stck)
{
	int	max_number;

	max_number = stck->number;
	stck = stck->next;
	while (stck != NULL)
	{
		if (stck->number < max_number)
			return (1);
		else
			max_number = stck->number;
		stck = stck->next;
	}
	return (0);
}

void	ft_rotate_max_up(t_stack **stack_b)
{
	int		median;
	t_stack	*max_element;

	max_element = ft_max_element(*stack_b);
	median = ft_stsize(*stack_b) / 2;
	if ((max_element->index) <= median)
	{
		while (max_element->index != 0)
			ft_rb(stack_b);
	}
	if ((max_element->index) > median)
	{
		while (max_element->index != 0)
			ft_rrb(stack_b);
	}
}
