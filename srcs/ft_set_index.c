/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:20:28 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/22 16:03:43 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_stack *stck)
{
	long	i;
	
	i = 0;
	while (stck != NULL)
	{
		stck->index = i;
		stck = stck->next;
		i++;
	}
}
