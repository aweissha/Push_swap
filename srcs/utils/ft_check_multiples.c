/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_multiples.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:57:20 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 13:25:49 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_multiples(char **array)
{
	int	i;
	int j;

	i = 0;
	while (array[i + 1] != NULL)
	{
		j = i + 1;
		while (array[j] != NULL)
		{
			if (ft_atoi_mod(array[i]) == ft_atoi_mod(array[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
