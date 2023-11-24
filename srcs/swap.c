/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:35:16 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/24 11:30:16 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stck)
{
	t_stack	*tmp;

	if (*stck != NULL && (*stck)->next != NULL)
	{
		tmp = *stck;
		*stck = (*stck)->next;
		tmp->next = (*stck)->next;
		(*stck)->next = tmp;
		(*stck)->previous = NULL;
		if (tmp->next != NULL)
			tmp->next->previous = tmp;
		tmp->previous = *stck;
		ft_set_index(*stck);
	}
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
