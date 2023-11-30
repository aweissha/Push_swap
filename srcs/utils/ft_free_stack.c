/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:08:36 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 13:26:09 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free_stack(t_stack *stck)
{
	t_stack	*tmp;

	tmp = stck;
	while (tmp != NULL)
	{
		tmp = stck->next;
		free(stck);
		stck = tmp;
	}
}
