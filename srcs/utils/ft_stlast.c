/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stlast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:44:35 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 16:33:07 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_stlast(t_stack *stck)
{
	if (stck == NULL)
		return (NULL);
	while (stck->next != NULL)
		stck = stck->next;
	return (stck);
}
