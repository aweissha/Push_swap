/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:39:02 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/19 18:08:46 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_make_stack_a(char **array)
{
	t_stack	*stack_a;
	int i;
	
	i = 0;
	stack_a = ft_stnew(ft_atoi(array[i]), i);
	i++;
	while (array[i] != NULL)
	{
		ft_stadd_back(&stack_a, ft_stnew(ft_atoi(array[i]), i));
		i++;
	}
}
