/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:54:56 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/22 16:56:51 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stck)
{
	t_stack	*tmp;
	t_stack *last;

	last = ft_stlast(*stck);
	tmp = (*stck)->next;
	last->next = *stck;
	(*stck)->next = NULL;
	(*stck)->previous = last;
	tmp->previous = NULL;
	*stck = tmp;
	ft_set_index(*stck);
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
