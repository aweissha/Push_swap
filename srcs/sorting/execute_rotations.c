/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:39:20 by aweissha          #+#    #+#             */
/*   Updated: 2023/12/01 15:01:55 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	m_all_top(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b)
{
	while (c->index != 0 && b->index != 0)
		ft_rr(st_a, st_b);
	while (c->index != 0)
		ft_ra(st_a);
	while (b->index != 0)
		ft_rb(st_b);
}

void	m_all_bot(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b)
{
	while (c->index != 0 && b->index != 0)
		ft_rrr(st_a, st_b);
	while (c->index != 0)
		ft_rra(st_a);
	while (b->index != 0)
		ft_rrb(st_b);
}

void	m_top_bot(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b)
{
	while (c->index != 0)
		ft_ra(st_a);
	while (b->index != 0)
		ft_rrb(st_b);
}

void	m_bot_top(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b)
{
	while (c->index != 0)
		ft_rra(st_a);
	while (b->index != 0)
		ft_rb(st_b);
}

void	rotate(t_stack **st_a, t_stack **st_b, t_stack *cheapest)
{
	t_stack	*targ_b;
	int		a;
	int		b;
	int		c;
	int		d;

	targ_b = ft_find_target(st_b, cheapest);
	a = all_top(cheapest, targ_b);
	b = all_bot(st_a, st_b, cheapest, targ_b);
	c = top_bot(st_b, cheapest, targ_b);
	d = bot_top(st_a, cheapest, targ_b);
	if (a <= b && a <= c && a <= d)
		m_all_top(st_a, st_b, cheapest, targ_b);
	else if (b <= a && b <= c && b <= d)
		m_all_bot(st_a, st_b, cheapest, targ_b);
	else if (c <= a && c <= b && c <= d)
		m_top_bot(st_a, st_b, cheapest, targ_b);
	else
		m_bot_top(st_a, st_b, cheapest, targ_b);
}
