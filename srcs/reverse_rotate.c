/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:15:48 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/28 18:58:16 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stck)
{
	t_stack	*last;
	
	if (*stck != NULL && (*stck)->next != NULL)
	{
		last = ft_stlast(*stck);
		last->previous->next = NULL;
		last->previous = NULL;
		last->next = *stck;
		(*stck)->previous = last;
		*stck = last;
		ft_set_index(*stck);		
	}
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
			// global_variable++; //entfernen
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
			// global_variable++; //entfernen
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
			// global_variable++; //entfernen
}
