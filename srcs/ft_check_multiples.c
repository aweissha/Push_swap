/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_multiples.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:57:20 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/21 12:19:31 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_multiples(t_stack *stck)
{
	t_stack *counter;
	
	while (stck->next != NULL)
	{
		counter = stck->next;
		while (counter != NULL)
		{
			if (counter->number == stck->number)
				return (1);
			counter = counter->next;
		}
		stck = stck->next;
	}
	return (0);
}
