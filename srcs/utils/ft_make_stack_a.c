/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:39:02 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 13:26:16 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_make_stack_a(char **array, t_stack **stack_a)
{
	int i;
	long n;
// check for errors first
	i = 0;
	while (array[i] != NULL)
	{
		if (ft_syntax_error(array[i]) == 1)
			return (1);			
		n = ft_atoi_mod(array[i]);
		if (n > INT32_MAX || n < INT32_MIN)
			return (1);
		i++;
	}
	if (ft_check_multiples(array) == 1)
		return (1);
// then initialization of stack_a
	i = 0;
	while (array[i] != NULL)
	{
		ft_stadd_back(stack_a, ft_stnew(ft_atoi_mod(array[i]), i));
		i++;
	}
	return (0);
}
