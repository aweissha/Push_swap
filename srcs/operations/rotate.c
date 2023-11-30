/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:54:56 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 16:24:46 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_rotate(t_stack **stck)
{
	t_stack	*tmp;
	t_stack *last;

	if (*stck != NULL && (*stck)->next != NULL)
	{
		last = ft_stlast(*stck);
		tmp = (*stck)->next;
		last->next = *stck;
		(*stck)->next = NULL;
		(*stck)->previous = last;
		tmp->previous = NULL;
		*stck = tmp;
		ft_set_index(*stck);		
	}
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
