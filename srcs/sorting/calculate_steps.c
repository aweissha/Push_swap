/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:35:54 by aweissha          #+#    #+#             */
/*   Updated: 2023/12/01 14:58:42 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	all_top(t_stack *a, t_stack *b)
{
	if ((a->index) >= (b->index))
		return (a->index);
	else
		return (b->index);
}

int	all_bot(t_stack **st_a, t_stack **st_b, t_stack *a, t_stack *b)
{
	if ((ft_stsize(*st_a) - (a->index)) >= (ft_stsize(*st_b) - (b->index)))
		return (ft_stsize(*st_a) - (a->index));
	else
		return (ft_stsize(*st_b) - (b->index));
}

int	top_bot(t_stack **st_b, t_stack *a, t_stack *b)
{
	return ((a->index) + (ft_stsize(*st_b) - (b->index)));
}

int	bot_top(t_stack **st_a, t_stack *a, t_stack *b)
{
	return ((b->index) + (ft_stsize(*st_a) - (a->index)));
}
