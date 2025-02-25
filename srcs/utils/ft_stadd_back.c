/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:41:31 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 13:27:35 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stadd_back(t_stack **stck, t_stack *new)
{
	t_stack	*last;

	if (stck && new)
	{
		if (*stck)
		{
			last = ft_stlast(*stck);
			last->next = new;
			new->previous = last;
		}
		else
			*stck = new;
	}
}
