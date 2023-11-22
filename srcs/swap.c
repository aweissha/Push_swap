/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:35:16 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/22 16:58:14 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stck)
{
	t_stack	*tmp;

	tmp = *stck;
	*stck = (*stck)->next;
	tmp->next = (*stck)->next;
	(*stck)->next = tmp;
	(*stck)->previous = NULL;
	tmp->next->previous = tmp;
	ft_set_index(*stck);
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
